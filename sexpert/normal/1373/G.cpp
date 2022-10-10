#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAGIC = 650;
const int MAXN = 6e5 + 10;
int cnt[MAXN], blcnt[MAXN], oper[MAXN];
set<pair<int, int>> used;

void recalc(int bl) {
    int cur = 0;
    for(int i = bl * MAGIC; i < bl * MAGIC + MAGIC; i++) {
        if(cnt[i] == 0)
            continue;
        cur = max(cur + cnt[i], i + cnt[i] - 1);
    }
    oper[bl] = cur;
}

int query() {
    int cur = 0;
    for(int b = 0; b < 1000; b++) {
        if(blcnt[b] == 0)
            continue;
        cur = max(cur + blcnt[b], oper[b]);
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int mn = y + abs(x - k);
        int bl = mn / MAGIC;
        //cout << "mn = " << mn << " " << bl << '\n';
        if(used.count({x, y})) {
            used.erase({x, y});
            cnt[mn]--;
            blcnt[bl]--;
            recalc(bl);
        }
        else {
            used.insert({x, y});
            cnt[mn]++;
            blcnt[bl]++;
            recalc(bl);
        }
        cout << max(query() - n, 0) << '\n';
    }
}