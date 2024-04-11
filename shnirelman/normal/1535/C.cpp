#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int l = 0, r = 0;
    char lst = '?';
    li ans = 0;
    int cnt = 0;

    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') {
            y++;
            cnt++;
            if(lst != '?') {
                lst = '1' - lst + '0';
            }
        } else if(lst == '?') {
//            x = y;
            y = 0;
            lst = s[i];
            cnt++;
        } else if(lst != s[i]) {
            y = 0;
            lst = s[i];
            cnt++;
        } else {
            ans += cnt * 1ll * (cnt + 1) / 2;
            ans -= x * 1ll * (x + 1) / 2;
            x = y;
            y = 0;
            cnt = 1 + x;
            lst = s[i];
        }
    }

    ans += cnt * 1ll * (cnt + 1) / 2;
    ans -= x * 1ll * (x + 1) / 2;

    cout << ans << endl;
//    while(r < n) {
//        if(lst == '?') {
//            lst = s[r];
//            r++;
//        } else if(lst != s[r]) {
//            lst = '1' - lst + '0';
//            cnt++;
//            r++;
//        } else {
//            break;
//        }
//    }
//
//    ans += r - l;
//    for(; l < n; l++) {
//
//    }

//    int cur = 0;
//    for(int i = 0; i < n; i++) {
//        if(s[i] == '?') {
//            cur++;
//            ans += cur;
//            continue;
//        }
//        int x = (s[i] - '0');
//        if(i % 2 == x) {
//            cur++;
//            ans += cur;
//        } else {
//            cur = 0;
//        }
//    }

}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}