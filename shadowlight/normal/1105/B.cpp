#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    int res = 0;
    for (int c = 0; c < 26; c++) {
        int cnt = 0;
        int all = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] - 'a' == c) {
                cnt++;
                if (cnt == k) {
                    all++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        res = max(res, all);
    }
    cout << res;
}