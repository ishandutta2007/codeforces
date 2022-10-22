#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 30;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string ans(n, '0');

    if(s[0] == '9') {
        bool fl = false;
        for(int i = n - 1; i >= 0; i--) {
            int x = 1 - int(s[i] - '0') - fl;
            if(x < 0) {
                fl = true;
                x += 10;
            } else {
                fl = false;
            }

            ans[i] = char(x + '0');
        }
    } else {
        for(int i = 0; i < n; i++) {
            ans[i] = '9' - s[i] + '0';
        }
    }

//    {
//        bool fl = false;
//        for(int i = 1; i < n; i++) {
//            if(s[i] != '0') {
//                fl = true;
//                break;
//            }
//        }
//
//        if(!fl) {
//            ans[0] = '1';
//            if(s[0] < '9')
//                ans[n - 1] = s[0] + 1;
//            else
//                ans[n - 1] = '1';
//
//            cout << ans << endl;
//            return 0;
//        }
//    }
//
//
////    ans[0] = '1';
//
//    int lst = (int(ans[0] - '0') + int(s[0] - '0'));
//    if(lst >= 10)
//        lst = 1;
//
////    cout << ans << ' ' << 11 - (s[n - 1] - '0') << ' ' << int(11 - (s[n - 1] - '0') + '0') << endl;
//
//    bool fl = false;
//    if(s[n - 1] == '0')
//        ans[n - 1] = '1';
//    else if(s[n - 1] > '1') {
//        ans[n - 1] = char(11 - (s[n - 1] - '0') + '0');
//        fl = true;
//    }
////    if(s[n - 1] <= '0' + lst)
////        ans[n - 1] = char(lst + '0' - s[n - 1] + '0');
////    else {
////        ans[n - 1] = char(10 + lst - (s[n - 1] - '0') + '0');
////        fl = true;
////    }
//
//    for(int i = n - 2; i > 0; i--) {
//        int x = int(s[i] - '0') + fl;
//
//        int y = 0;
//        if(x % 10 != 0) {
//            y = 10 - x;
//        }
//
//        ans[i] = char('0' + y);
//        fl = (x + y >= 10);
//    }
//
//    int x = int(s[0] - '0') + fl;
//
//    ans[0] = char('0' + 11 - x);

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