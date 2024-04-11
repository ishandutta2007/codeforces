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
    int l, w;
    cin >> w >> l;
    vector <int> a(w + 1, 0);
    for (int i = 1; i < w; i++) {
        cin >> a[i];
    }
    a[w] = INF;
    queue <pair <int, int> > q;
    q.push({0, INF});
    for (int i = 1; i <= w; i++) {
        int x = a[i];
        while (q.size() && q.front().first + l < i) {
            q.pop();
        }
        int cnt = 0;
        while (q.size() && q.front().second <= x) {
            cnt += q.front().second;
            x -= q.front().second;
            q.pop();
        }
        if (q.size() && q.front().second > x) {
            q.front().second -= x;
            cnt += x;
        }
        //cout << cnt << "\n";
        q.push({i, cnt});
    }
    int res = 0;
    while (q.size()) {
        res += q.front().second;
        q.pop();
    }
    cout << res;
}