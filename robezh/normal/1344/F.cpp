#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

mt19937 rng(2333);

int solve(vi v) {
    while(v.size() >= 2) {
        int x = v.back(); v.pop_back();
        int y = v.back(); v.pop_back();
        if(x != y) v.push_back(3 - x - y);
    }
    return (v.empty() ? -1 : v[0]);
}

const int N = 2005;

typedef bitset<N> bs;

int solveLinear(vector<bs>& A, vi& b, bs& x, int m) {
    int n = sz(A), rank = 0, br;
    assert(m <= sz(x));
    vi col(m); iota(all(col), 0);
    rep(i,0,n) {
        for (br=i; br<n; ++br) if (A[br].any()) break;
        if (br == n) {
            rep(j,i,n) if(b[j]) return -1;
            break;
        }
        int bc = (int)A[br]._Find_next(i-1);
        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j,0,n) if (A[j][i] != A[j][bc]) {
                A[j].flip(i); A[j].flip(bc);
            }
        rep(j,i+1,n) if (A[j][i]) {
                b[j] ^= b[i];
                A[j] ^= A[i];
            }
        rank++;
    }

    x = bs();
    for (int i = rank; i--;) {
        if (!b[i]) continue;
        x[col[i]] = 1;
        rep(j,0,i) b[j] ^= A[j][i];
    }
    return rank; // (multiple solutions if rank < m)
}

using mtx = vector<vi>;
int n, k;
vector<mtx> v;
vector<mtx> mats = {{{0, 1}, {1, 0}}, {{1, 1}, {0, 1}}, {{1, 0}, {1, 1}}};
map<char, int> mp;
string chs = "WRYB";

mtx matmul(mtx a, mtx b) {
    mtx c(2, vi(2, 0));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) c[i][j] ^= (a[i][k] * b[k][j]);
        }
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    rep(i, 0, 4) mp[chs[i]] = i;
    cin >> n >> k;
    v = vector<mtx> (n, mtx(2, vi(2)));
    for(int i = 0; i < n; i++) {
        rep(j, 0, 2) rep(t, 0, 2) v[i][j][t] = (j == t);
    }
    vector<bs> A;
    vi B;

    for(int i = 0; i < k; i++) {
        string str;
        int m;
        cin >> str >> m;
        vector<int> vs(m);
        for(int j = 0; j < m; j++) cin >> vs[j], vs[j]--;
        if(str == "mix") {
            char c; cin >> c;
            int y = mp[c];
//            cout << y << endl;
            bs a0;
            bs a1;
//            a0.reset();
//            a1.reset();
            for(int j : vs) {
                a0[j * 2] = v[j][0][0];
                a0[j * 2 + 1] = v[j][0][1];
                a1[j * 2] = v[j][1][0];
                a1[j * 2 + 1] = v[j][1][1];
            }
            A.push_back(a0), A.push_back(a1);
            B.push_back(y & 1), B.push_back((y >> 1) & 1);
//            cout << a0 << " " << (y & 1) << endl;
//            cout << a1 << " " << ((y >> 1) & 1) << endl;
        }
        else {
            mtx mat = (str == "RY" ? mats[0] : (str == "YB" ? mats[1] : mats[2]));
            for(int j : vs) v[j] = matmul(mat, v[j]);
        }
    }
    bs x;
    if(solveLinear(A, B, x, 2 * n) == -1) {
        cout << "NO\n";
    } else {
//        cout << x << endl;
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            char c = chs[(int)x[i * 2] + ((int)x[i * 2 + 1] << 1)];
            if(c == 'W') c = '.';
            cout << c;
        }
        cout << '\n';
    }



}