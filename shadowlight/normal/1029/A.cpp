#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = n;
    for (int i = n - 1; i >= 1; i--) {
        if (s.substr(0, i) == s.substr(n - i, i)) {
            cnt = i;
            break;
        }
    }
    if (cnt == n) {
        for (int i = 0; i < k; i++) {
            cout << s;
        }
        return 0;
    }
    string t = s.substr(0, cnt);
    for (int i = 0; i < k; i++) {
        t += s.substr(cnt, n);
    }
    cout << t;
}