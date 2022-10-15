#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

#define ll long long

vector<pair<ll, int> > events;

int n;
ll ans[200005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ll l, r; scanf("%lld%lld", &l, &r);
        events.push_back(make_pair(l, 1));
        events.push_back(make_pair(r+1, -1));
    }
    sort(events.begin(), events.end());
    int curv = 0;
    for (int i = 0; i < events.size(); i++) {
        curv += events[i].second;
        if (i != (int)(events.size() - 1) && events[i+1].first != events[i].first) {
            ans[curv] += events[i+1].first - events[i].first;
        }
    }
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
    return 0;
}