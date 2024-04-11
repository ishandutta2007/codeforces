//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/

void solve() {
    string s;
    cin >> s;

    int ans = 10;
    {
        string s1 = s;
        for(int i = 0; i < 10; i++) {
            if(s1[i] == '?')
                s1[i] = (i % 2 == 0 ? '1' : '0');
        }
//        cout << s1 << endl;

        int cur = 0;
        for(int i = 0; i < 10; i++) {
            if(s1[i] == '1')
                cur += ((i % 2 == 0) ? 1 : -1);
//            cout << i << ' ' << cur << ' ' << (9 - i) / 2 << endl;
            if(cur > (10 - i) / 2) {
                ans = i + 1;
                break;
            }
        }
    }

    {
        string s1 = s;
        for(int i = 0; i < 10; i++) {
            if(s1[i] == '?')
                s1[i] = (i % 2 == 1 ? '1' : '0');
        }
//        cout << s1 << endl;

        int cur = 0;
        for(int i = 0; i < 10; i++) {
            if(s1[i] == '1')
                cur += ((i % 2 == 1) ? 1 : -1);
//            cout << i << ' ' << cur << ' ' << (9 - i) / 2 << endl;
            if(cur > (9 - i) / 2) {
                ans = min(ans, i + 1);
                break;
            }
        }
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