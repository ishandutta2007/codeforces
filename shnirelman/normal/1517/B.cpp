#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 113;
const int LOGN = 20;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*

*/

mt19937 rnd(3666);

int a[N][N];
bool used[N][N];
int b[N][N];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            used[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++) {
        sort(a[i], a[i] + m);
    }

//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            cout << a[i][j] << ' ';
//        }
//        cout << endl;
//    }

    set<pair<int, pii>> st;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            st.insert({a[i][j], {i, j}});
        }
    }

//    for(auto p : st) {
//        cout << p.f << ' ' << p.s.f << ' ' << p.s.s << endl;
//    }

    for(int ind = 0; ind < m; ind++) {
        int i1 = st.begin()->s.f, j1 = st.begin()->s.s;
        st.erase(st.begin());

//        cout << "for " << ind << ' ' << i1 << ' ' << j1 << ' ' << a[i1][j1] << endl;

        for(int i = 0; i < n; i++) {
            if(i1 == i) {
                b[i][ind] = a[i1][j1];
                used[i1][j1] = true;
            } else {
                for(int j = m - 1; j >= 0; j--) {
                    if(!used[i][j]) {
                        b[i][ind] = a[i][j];
                        st.erase({a[i][j], {i, j}});
                        used[i][j] = true;
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}