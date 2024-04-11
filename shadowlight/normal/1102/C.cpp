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
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    multiset <int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.insert(x);
    }
    if (x > y) {
        cout << n << "\n";
        return 0;
    }
    int cnt = 0;
    while (!q.empty()) {
        int a = *q.begin();
        q.erase(q.begin());
        if (a <= x) {
            cnt++;
        } else break;
        if (q.size()) {
            int b = *q.begin();
            q.erase(q.begin());
            b += y;
            q.insert(b);
        }
    }
    cout << cnt;
}