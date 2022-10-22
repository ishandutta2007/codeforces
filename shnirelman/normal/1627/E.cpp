#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;

/*
1
5 5 5
3 2 3 7 5
3 5 4 2 1
2 2 5 4 5
4 4 5 2 3
1 2 4 2 2
3 3 5 2 4
*/

struct Ladder {
    int a, b, c, d, h;

    Ladder() {};

    Ladder(int a, int b, int c, int d, int h) : a(a), b(b), c(c), d(d), h(h) {};
};

int x[N];
map<int, vector<Ladder>> lad[N];
map<int, li> bst[N];

void solve(bool debug_out) {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for(int i = 0; i < n; i++) {
        lad[i].erase(lad[i].begin(), lad[i].end());
        bst[i].erase(bst[i].begin(), bst[i].end());

    }

    for(int i = 0; i < k; i++) {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;

        a--;
        b--;
        c--;
        d--;

        lad[a][b].push_back(Ladder(a, b, c, d, h));
    }

    bst[0][0] = 0;

    for(int i = 0; i < n; i++) {
        err << "floor i = " << i << endl;
        set<int> st;
        for(auto p : bst[i]) {
            st.insert(p.f);
            err << p.f << ' ' << p.s << endl;
        }

        for(auto p : lad[i])
            st.insert(p.f);

        vector<int> js(st.begin(), st.end());

        err << "js : ";
        for(int j : js) {
            err << j << ' ';
        }
        err << endl;

        li cur = INF64;
        int lst = 0;
        for(int j : js) {
            cur += (j - lst) * 1ll * x[i];
            if(bst[i].count(j)) {
                cur = min(cur, bst[i][j]/* - j * 1ll * x[i]*/);
            }
            err << "for1 : " << j << ' ' << cur << ' ' << endl;

            for(auto a : lad[i][j]) if(cur < INF64) {
                int c = a.c, d = a.d, h = a.h;
                li res = cur - h;
                if(bst[c].count(d) == 0 || bst[c][d] > res)
                    bst[c][d] = res;
            }
            lst = j;
        }

        reverse(js.begin(), js.end());
        cur = INF64;
        lst = m - 1;
        for(int j : js) {
            cur += (lst - j) * 1ll * x[i];
            if(bst[i].count(j)) {
                cur = min(cur, bst[i][j]/* - j * 1ll * x[i]*/);
            }

            for(auto a : lad[i][j]) if(cur < INF64) {
                int c = a.c, d = a.d, h = a.h;
                li res = cur - h;
                if(bst[c].count(d) == 0 || bst[c][d] > res)
                    bst[c][d] = res;
            }
            lst = j;
        }

        err << endl;
    }

    if(bst[n - 1].size() == 0) {
        cout << "NO ESCAPE" << endl;
        return;
    }

    li ans = INF64;
    for(auto p : bst[n - 1]) {
        ans = min(ans, p.s + (m - 1 - p.f) * 1ll * x[n - 1]);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve(0);
}