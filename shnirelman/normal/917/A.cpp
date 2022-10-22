#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 14;
const int M = 998244353;
const int N = 5000 + 13;

bool is[N][N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();

    string s;
    cin >> s;

    int ans = 0;

    set<pii> st;

    for(int i = s.size() - 1; i >= 0; i--) {
        int a = 0, b = 0;
        for(int j = i; j >= 0; j--) {
            if(s[j] == ')')
                a++;
            else if(s[j] == '(')
                a--;
            else {
                a++;
                b++;
            }

            if(a < 0)
                break;

//            cout << i << ' ' << j << ' ' << a << ' ' << b << endl;

            if((j - i + 1) % 2 == 0 && a - 2 * b <= 0) {
                is[j][i] = true;
//                st.insert({j, i});
//                ans++;
//                cout << i << ' ' << j << endl;
            }
        }
    }

    for(int i = 0; i < s.size(); i++) {
        int a = 0, b = 0;
        for(int j = i; j < s.size(); j++) {
            if(s[j] == '(')
                a++;
            else if(s[j] == ')')
                a--;
            else {
                a++;
                b++;
            }

            if(a < 0)
                break;

//            cout << i << ' ' << j << ' ' << a << ' ' << b << endl;

            if((j - i + 1) % 2 == 0 && a - 2 * b <= 0) {
                ans += is[i][j];//st.count({i, j});
//                cout << i << ' ' << j << endl;
            }

        }
    }

    cout << ans << endl;
}