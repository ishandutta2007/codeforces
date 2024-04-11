#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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

int n;

int a[500005], b[500005];
bool sused[1100005];

list<pair<int, int> > graph[1100005];
int degree[1100005];
bool used[1100005];
int uf[1100005];
multimap<pair<int, int>, pair<int, int> > nod2orig;

vector<int> ans;

int fin(int x)
{
    if (uf[x] == x) return x;
    return uf[x] = fin(uf[x]);
}

void un(int A, int B)
{
    A = fin(A); B = fin(B);
    if (A == B) return;
    uf[A] = B;
}

bool check(int bits)
{
    int mask = (1 << bits) - 1;
    for (int i = 0; i <= mask; i++) uf[i] = i;
    for (int i = 0; i <= mask + 5; i++) degree[i] = 0;
    for (int i = 1; i <= n; i++) {
        degree[a[i] & mask]++; degree[b[i] & mask]++;
        un(a[i] & mask, b[i] & mask);
    }
    int bas = fin(a[1] & mask);
    for (int i = 1; i <= n; i++) {
        if (fin(a[i] & mask) != bas) return false;
        if (fin(b[i] & mask) != bas) return false;
    }
    int oddcnt = 0;
    for (int i = 0; i <= mask; i++) {
        if (degree[i] & 1) oddcnt++;
    }
    return oddcnt == 0;
}

void build(int bits)
{
    nod2orig.clear(); ans.clear();
    int nextedge = 1;
    for (int i = 0; i < 1100005; i++) used[i] = false, sused[i] = false;
    int mask = (1 << bits) - 1;
    for (int i = 0; i <= mask + 5; i++) graph[i].clear(), degree[i] = 0;
    int start = 0;
    for (int i = 1; i <= n; i++) {
        start = (a[i] & mask);
        nod2orig.insert(make_pair(make_pair(a[i] & mask, b[i] & mask),
            make_pair(2 * i - 1, 2 * i)));
        graph[a[i] & mask].push_back(make_pair(b[i] & mask, nextedge));
        if ((a[i] & mask) != (b[i] & mask)) {
            graph[b[i] & mask].push_back(make_pair(a[i] & mask, nextedge));
            nod2orig.insert(make_pair(make_pair(b[i] & mask, a[i] & mask),
                make_pair(2 * i, 2 * i - 1)));
        }
        degree[a[i] & mask]++; degree[b[i] & mask]++;
        nextedge++;
    }

    deque<int> tour;
    int remaining = n;
    tour.push_back(start);
    while (remaining) {
        while (!graph[tour.front()].empty() && used[graph[tour.front()].begin()->second]) {
            graph[tour.front()].pop_front();
        }
        while (graph[tour.front()].empty()) {
            tour.pop_front(); tour.push_back(tour.front());
            while (!graph[tour.front()].empty() && used[graph[tour.front()].begin()->second]) {
                graph[tour.front()].pop_front();
            }
        }
        int newnode = graph[tour.front()].begin()->first;
        int edgeid = graph[tour.front()].begin()->second;
        used[edgeid] = true;
        tour.push_front(newnode);
        remaining--;
    }
    int pre = -1;
    while (!tour.empty()) {
        int cur = tour.front();
        //debug("%d ", cur);
        tour.pop_front();
        if (pre != -1) {
            while (true) {
                auto it = nod2orig.find(make_pair(pre, cur));
                int nod = min(it->second.first, it->second.second);
                if (!sused[nod]) {
                    ans.push_back(it->second.first);
                    ans.push_back(it->second.second);
                    sused[nod] = true;
                    nod2orig.erase(it); break;
                }
                nod2orig.erase(it);
            }
        }
        pre = cur;
    }
    //debug("\n");
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", a + i, b + i);
    }
    int l = 0, r = 20;
    while (l < r) {
        int mid = (l + r) / 2 + 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    build(l);
    printf("%d\n", l);
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    return 0;
}