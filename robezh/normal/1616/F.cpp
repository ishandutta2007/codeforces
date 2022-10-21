#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 65, INF = (int)1e9;
const int M = 256;

int n, m;

int eid[N][N];

struct v3 {
    bitset<M> v[3];
    int getv(int x) {
        if(v[0][x]) return 0;
        else if(v[1][x]) return 1;
        else {
            return 2;
        }
    }

    int first_nonzero() {
        int rs = min(v[2]._Find_first(), v[1]._Find_first());
        return min(rs, m);
    }

    v3 mul(int x) {
        v3 res = *this;
        if(x == 0) res.v[0].reset(), res.v[1].reset(), res.v[2].reset();
        else if(x == 2) swap(res.v[1], res.v[2]);
        return res;
    }

    string getval() {
        string res;
        rep(i, 0, m) res.push_back((char)('0' + getv(i)));
        return res;
    }

};

v3 operator + (v3 a, v3 b) {
    v3 res;
    res.v[0] = (a.v[0] & b.v[0]) | (a.v[1] & b.v[2]) | (a.v[2] & b.v[1]);
    res.v[1] = (a.v[0] & b.v[1]) | (a.v[1] & b.v[0]) | (a.v[2] & b.v[2]);
    res.v[2] = (~res.v[0] & ~res.v[1]);
    return res;
}

int dvi[3][3] = {
        {0, 0, 0},
        {-1, 1, 2},
        {-1, 2, 1},
};

v3 create(vi vs) {
    v3 a;
    for (int x : vs) a.v[1][x] = true;
    a.v[0] = ~a.v[1];
    return a;
}


struct Basis {
    vector<v3> A;
    vi B;

    void clear() {
        A.clear();
        B.clear();
    }

    bool add(v3 a, int b) {
        for (int i = 0; i < sz(A); i++) {
            int c = a.first_nonzero();
            if(c == A[i].first_nonzero()) {
                int d = dvi[a.getv(c)][A[i].getv(c)];
                int f = (d * 2 % 3);
                a = a + A[i].mul(f);
                b = (b + B[i] * f) % 3;
            }
        }

        if(a.first_nonzero() == m) {
            if(b != 0) return false;
        } else {
            int idx = sz(A);
            int c = a.first_nonzero();
            while(idx - 1 >= 0 && A[idx - 1].first_nonzero() > c) idx--;
            A.insert(A.begin() + idx, a);
            B.insert(B.begin() + idx, b);
        }

        return true;
    }

    vi solve() {
        vi res(m, 0);
        for (int i = sz(A) - 1; i >= 0; i--) {
            int c = A[i].first_nonzero();
            res[c] = B[i];
            for (int j = c + 1; j < m; j++) {
                res[c] -= res[j] * A[i].getv(j);
            }
            res[c] = (res[c] % 3 + 3) % 3;
            res[c] = dvi[res[c]][A[i].getv(c)];
        }
        return res;
    }

} basis;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) fill(eid[i], eid[i] + n, -1);
        basis.clear();

        rep(i, 0, m) {
            int a, b, c; cin >> a >> b >> c; a--, b--;
            eid[a][b] = eid[b][a] = i;
            if(c != -1) basis.add(create({i}), c - 1);
        }

        bool good = true;
        rep(i, 0, n) {
            rep(j, i + 1, n) {
                rep(k, j + 1, n) {
                    if(eid[i][j] != -1 && eid[j][k] != -1 && eid[i][k] != -1) {
                        good &= basis.add(create({eid[i][j], eid[j][k], eid[i][k]}), 0);
                    }
                }
            }
        }
        if(!good) {
            cout << -1 << '\n';
        } else {
            vi res = basis.solve();
            rep(i, 0, m) cout << res[i] + 1 << " ";
            cout << '\n';
        }

    }

}