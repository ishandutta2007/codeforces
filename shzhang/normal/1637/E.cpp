#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int a[300005];

void work()
{
    int n, m; scanf("%d%d", &n, &m);
    map<int, int> freq;
    map<int, vector<int> > groups;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        freq[a[i]]++;
    }
    set<pair<int, int> > bad;
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        bad.insert(make_pair(x, y));
        bad.insert(make_pair(y, x));
    }
    set<int> done;
    set<int> cntsset;
    for (int i = 1; i <= n; i++) {
        bad.insert(make_pair(a[i], a[i]));
        if (!done.count(a[i])) {
            groups[freq[a[i]]].push_back(a[i]);
            cntsset.insert(freq[a[i]]);
            done.insert(a[i]);
        }
    }
    vector<int> cnts;
    while (!cntsset.empty()) {
        cnts.push_back(*cntsset.begin());
        cntsset.erase(cntsset.begin());
    }
    for (int i = 0; i < cnts.size(); i++) {
        sort(groups[cnts[i]].begin(), groups[cnts[i]].end());
        reverse(groups[cnts[i]].begin(), groups[cnts[i]].end());
    }
    ll ans = 0;
    for (int idx1 = 0; idx1 < cnts.size(); idx1++) {
        for (int idx2 = idx1; idx2 < cnts.size(); idx2++) {
            int cnt1 = cnts[idx1];
            int cnt2 = cnts[idx2];
            priority_queue<pair<int, pair<int, int> > > pq;
            set<pair<int, int> > inque;
            pq.push(make_pair(groups[cnt1][0] + groups[cnt2][0],
                make_pair(0, 0)));
            inque.insert(make_pair(0, 0));
            while (!pq.empty()) {
                pair<int, pair<int, int> > elem = pq.top();
                pq.pop();
                if (!bad.count(make_pair(groups[cnt1][elem.second.first],
                    groups[cnt2][elem.second.second]))) {
                    ans = max(ans, (ll)(cnt1 + cnt2) * (ll)(elem.first));
                    break;
                }
                int u = elem.second.first;
                int v = elem.second.second;
                if (u + 1 < groups[cnt1].size() &&
                    !inque.count(make_pair(u+1, v))) {
                    pq.push(make_pair(groups[cnt1][u + 1] +
                        groups[cnt2][v], make_pair(u+1, v)));
                    inque.insert(make_pair(u+1, v));
                }
                if (v + 1 < groups[cnt2].size() &&
                    !inque.count(make_pair(u, v+1))) {
                    pq.push(make_pair(groups[cnt1][u] +
                        groups[cnt2][v + 1], make_pair(u, v + 1)));
                    inque.insert(make_pair(u, v + 1));
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}