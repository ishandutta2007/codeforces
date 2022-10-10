#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bitset<2005> bs;
typedef vector<int> vi;
typedef array<int, 4> m2;

#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i,j,n) for(int i = j; i < n; i++)

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

map<char, int> cnv = {{'W', 0}, {'R', 1}, {'B', 2}, {'Y', 3}};
map<string, m2> lit = {{"RB", {0, 1, 1, 0}}, {"RY", {1, 0, 1, 1}}, {"YB", {1, 1, 0, 1}}};
string icv = ".RBY";

m2 mul(m2 a, m2 b) {
    m2 c = {(a[0]&b[0])^(a[1]&b[2]), (a[0]&b[1])^(a[1]&b[3]), (a[2]&b[0])^(a[3]&b[2]), (a[2]&b[1])^(a[3]&b[3])};
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, eq = 0;
    cin >> n >> k;

    vi res;
    vector<bs> A;
    vector<m2> cof(n, m2{1, 0, 0, 1});
    for(int i = 0; i < k; i++) {
        string ty;
        cin >> ty;
        if(ty != "mix") {
            m2 fac = lit[ty];
            int r;
            cin >> r;
            while(r--) {
                int x;
                cin >> x;
                x--;
                cof[x] = mul(fac, cof[x]);
            }
        }
        else {
            A.push_back(bs());
            A.push_back(bs());
            int r;
            cin >> r;
            while(r--) {
                int x;
                cin >> x;
                x--;
                A[2*eq][2*x] = cof[x][0];
                A[2*eq][2*x + 1] = cof[x][1];
                A[2*eq + 1][2*x] = cof[x][2];
                A[2*eq + 1][2*x + 1] = cof[x][3];
            }
            char col;
            cin >> col;
            if(col == 'W' || col == 'B')
                res.push_back(0);
            else
                res.push_back(1);
            if(col == 'W' || col == 'R')
                res.push_back(0);
            else
                res.push_back(1);
            eq++;
        }
    }
    //for(auto b : A) {
    //    for(int i = 0; i < 2*n; i++)
    //        cout << b[i];
    //    cout << '\n';
    //}
    //for(auto x : res)
    //    cout << x << " ";
    //cout << '\n';
    bs sol;
    int rk = solveLinear(A, res, sol, 2*n);
    if(rk == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    //for(int i = 0; i < 2*n; i++)
    //    cout << sol[i];
    //cout << '\n';
    for(int i = 0; i < n; i++)
        cout << icv[sol[2*i] + 2*sol[2*i + 1]];
    cout << '\n';
}