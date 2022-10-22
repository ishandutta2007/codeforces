#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    string s;
    cin >> s;
    ll all = 0;
    for (char c : s) {
        if (c == 'Q') {
            all++;
        }
    }
    ll ans = 0;
    ll cnt = 0;
    for (char c : s) {
        if (c == 'Q') {
            cnt++;
        } else if (c == 'A') {
            ans += cnt * (all - cnt);
        }
    }
    cout << ans;
}