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
    int n;
    cin >> n;
    int ans = 0;
    map <int, int> pos;
    int now = 0;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == '1') {
            now++;
        } else {
            now--;
        }
        if (!now) {
            ans = i + 1;
        } else if (pos[now]) {
            ans = max(ans, i - pos[now] + 1);
        }
        //cout << i << " " << pos[now] << "\n";
        if (!pos[now]) {
            pos[now] = i + 1;
        }
    }
    cout << ans;
}