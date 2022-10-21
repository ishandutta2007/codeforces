#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const int N = 3005, INF = (int)1e9 + 50;

int n, m, a, b;
ll g0, x, y, z;

int num[N][N];
ll mn[N];

struct MonQueue {
    deque<P> que;

    void clear() {
        que.clear();
    }
    void add(P p) {
        while(!que.empty() && que.back().first >= p.first) que.pop_back();
        que.push_back(p);
    }

    int get(int l, int r) {
        while(!que.empty() && (que.front().second < l || que.front().second > r)) que.pop_front();
        return que.empty() ? -INF : que.front().first;
    }
} mque[N], cque;

int main() {
    cin >> n >> m >> a >> b;
    cin >> g0 >> x >> y >> z;
    num[0][0] = (int)g0;
    ll cur = g0;
    for(int i = 1; i < n * m; i++) {
        cur = (cur * x + y) % z;
        num[i / m][i % m] = (int)cur;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < b - 1; j++) mque[i].add({num[i][j], j});
    }
    ll res = 0;
    for(int j = b - 1; j < m; j++) {
        for(int i = 0; i < n; i++) mque[i].add({num[i][j], j});
        cque.clear();
        for(int i = 0; i < a - 1; i++) cque.add({mque[i].get(j - b + 1, j), i});
        for(int i = a - 1; i < n; i++) {
            cque.add({mque[i].get(j - b + 1, j), i});
            res += cque.get(i - a + 1, i);
        }
    }
    cout << res << endl;

}