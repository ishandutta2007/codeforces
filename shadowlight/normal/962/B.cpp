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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int len = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            len++;
        } else {
            if (len) {
                if (a > b) {
                    swap(a, b);
                }
                res += min(a, len / 2);
                res += min(b, (len + 1) / 2);
                a -= min(a, len / 2);
                b -= min(b, (len + 1) / 2);
            }
            len = 0;
        }
    }
    if (len) {
        if (a > b) {
            swap(a, b);
        }
        res += min(a, len / 2);
        res += min(b, (len + 1) / 2);
        a -= min(a, len / 2);
        b -= min(b, (len + 1) / 2);
    }
    cout << res;
}