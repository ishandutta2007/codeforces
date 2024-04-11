//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
7
1 2
1 2
3 2
1 1 2 2 3 3
3 3
3 4 4 1 1 1 1 1 2
2 2
1 1 2 1
4 2
50 50 50 50 3 50 50 50
4 2
6 6 6 6 2 2 9 6
2 9
1 3 3 3 3 3 1 1 3 1 3 1 1 3 3 1 1 3

1
1 2
1 2

1
2 2
1 1 2 1

1
4 2
50 50 50 50 3 50 50 50
*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n * m);
    map<int, vector<int>> mp;
    for(int i = 0; i < n * m; i++) {
        cin >> a[i];

        mp[a[i]].push_back(i);
    }

//    sort(a.begin(), a.end());

    int ans = 0;
    vector<vector<int>> b(n, vector<int> (m, -1));
    int cur = 0;
    for(auto p : mp) {
//        cout << p.f << endl;
        int cnt = p.s.size();

        int x = (cur + m) / m * m - cur;
//            for(int i = p.s.size() - 1; i >= 0; i--) {
//                b[cur / m][cur % m] = p.s[i];
//                cur++;
//            }
        if(x >= cnt) {
            for(int i = p.s.size() - 1; i >= 0; i--) {
                b[cur / m][cur % m] = p.s[i];
                cur++;
            }
        } else {
//            for(auto y : p.s)
//                cout << y << ' ';
//            cout << endl;
//            cout << "x " << x << endl;
            for(int i = x - 1; i >= 0; i--) {
                b[cur / m][cur % m] = p.s[i];
                cur++;
            }
//            cout << "sag" << endl;
            for(int j = 0; ; j++) {
//                    cout << "j : " << j << endl;
                if(j * m + m + x > cnt)
                    break;
                for(int i = x + j * m + m - 1; i >= x + j * m; i--) {
//                    cout << j << ' ' << i << ' ' << p.s.size() << endl;
                    b[cur / m][cur % m] = p.s[i];
                    cur++;
                }
            }

            int y = (cnt - x) % m;

            for(int i = p.s.size() - 1; i >= p.s.size() - y; i--) {
//                    cout << i << endl;
                b[cur / m][cur % m] = p.s[i];
                cur++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
//            cout << b[i][j] << ' ';
//            cout << i << ' ' << j << ' ' << b[i].s<< endl;
            for(int k = 0; k < j; k++) {
                ans += (b[i][j] > b[i][k]);
            }
        }

//        cout << endl;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}