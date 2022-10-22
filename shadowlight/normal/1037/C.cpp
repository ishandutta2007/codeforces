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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt = 0, res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            if (cnt) {
                cnt = 0;
                res++;
            }
            cnt = 0;
        } else {
            cnt++;
            if (cnt == 2) {
                res++;
                if (s[i] == s[i - 1]) {
                    cnt = 1;
                } else {
                    cnt = 0;
                }
            }
        }
    }
    if (cnt) {
        res++;
    }
    cout << res;
}