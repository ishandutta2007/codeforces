#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
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

// FROM http://www.cs.cmu.edu/afs/cs/academic/class/15451-f14/www/lectures/lec11/dinic->pdf

const int MAXV = 120002, MAXE = 155000, INF = 10000;
template <typename T> struct Dinic {
int V, source, sink;
int eind, eadj [2 * MAXE], eprev [2 * MAXE], elast [MAXV], start [MAXV];
int front, back, q [MAXV], dist [MAXV];
T CAPINF, ecap [2 * MAXE];
int dfscount;
inline Dinic () {
V = -1;
CAPINF = numeric_limits <T> :: max ();
}
inline void init (int v) {
V = v; eind = 0;
memset (elast, -1, V * sizeof (int));
dfscount = 0;
}
inline void addedge (int a, int b, T cap1, T cap2) {
eadj [eind] = b; ecap [eind] = cap1; eprev [eind] = elast [a]; elast [a] = eind++;
eadj [eind] = a; ecap [eind] = cap2; eprev [eind] = elast [b]; elast [b] = eind++;
}
bool bfs () {
memset (dist, 63, V * sizeof (int));
front = back = 0;
q [back++] = source; dist [source] = 0;
while (front < back)
{
int top = q [front++];
for (int i = elast [top]; i != -1; i = eprev [i])
if (ecap [i] > 0 && dist [top] + 1 < dist [eadj [i]])
{
dist [eadj [i]] = dist [top] + 1;
q [back++] = eadj [i];
}
}
return dist [sink] < INF;
}

T dfs (int num, T pcap) {
dfscount++;
if (num == sink)
return pcap;
T total = 0;
for (int &i = start [num]; i != -1; i = eprev [i])
if (ecap [i] > 0 && dist [num] + 1 == dist [eadj [i]])
{
T p = dfs (eadj [i], min (pcap, ecap [i]));
ecap [i] -= p;
ecap [i ^ 1] += p;
pcap -= p;
total += p;
if (pcap == 0)
break;
}
return total;
}
T flow (int _source, int _sink) {
if (V == -1)
return -INF;
source = _source; sink = _sink;
T total = 0;
while (bfs ())
{
memcpy (start, elast, V * sizeof (int));
total += dfs (source, CAPINF);
}
return total;
}
};

int n, m, male, female;

int absolute(int A)
{
    if (A < 0) return -A;
    return A;
}

bool ismale[500]; int r[500], c[500]; ll t[500];
int scnt;

void read(int idx, bool is_male)
{
    scanf("%d%d%lld", r + idx, c + idx, t + idx);
    ismale[idx] = is_male;
}

bool Free[25][25];
bool vis[25][25];

#define valid(pr) (pr.first >= 1 && pr.first <= n \
    && pr.second >= 1 && pr.second <= m && Free[pr.first][pr.second] \
    && !vis[pr.first][pr.second])

#define add(pr) do {bfs.push(pr); vis[pr.first][pr.second] = true;} while (0)

bool check(ll tim)
{
    /* 1 - source; 2 - sink; 3 to scnt + 2 - scaygers;
       scnt + 2 + ((i - 1) * m + j) * 2 maybe - 1 - locations */

    Dinic<ll>* dinic = new Dinic<ll>;
    dinic->init(scnt + 2 + n * m * 2 + 10);
    for (int id = 1; id <= scnt; id++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) vis[i][j] = false;
        }
        queue<pair<int, int> > bfs;
        bfs.push(make_pair(r[id], c[id])); vis[r[id]][c[id]] = true;
        for (int round = 1; round <= tim / t[id]; round++) {
            int found = 0;
            int siz = (int)bfs.size();
            for (int i = 1; i <= siz; i++) {
                pair<int, int> cur = bfs.front();
                bfs.pop();
                pair<int, int> left = make_pair(cur.first, cur.second - 1);
                pair<int, int> right = make_pair(cur.first, cur.second + 1);
                pair<int, int> up = make_pair(cur.first - 1, cur.second);
                pair<int, int> down = make_pair(cur.first + 1, cur.second);
                if (valid(left)) {add(left); found++;}
                if (valid(right)) {add(right); found++;}
                if (valid(up)) {add(up); found++;}
                if (valid(down)) {add(down); found++;}
            }
            if (!found) break;
        }
        if (ismale[id]) {
            dinic->addedge(1, id + 2, 1, 0);
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (vis[i][j]) {
                        dinic->addedge(id + 2, scnt + 2 + ((i - 1) * m + j) * 2 - 1, 1, 0);
                    }
                }
            }
        } else {
            dinic->addedge(id + 2, 2, 1, 0);
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (vis[i][j]) {
                        dinic->addedge(scnt + 2 + ((i - 1) * m + j) * 2, id + 2, 1, 0);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dinic->addedge(scnt + 2 + ((i - 1) * m + j) * 2 - 1, scnt + 2 + ((i - 1) * m + j) * 2, 1, 0);
        }
    }
    int res = dinic->flow(1, 2);
    delete dinic;
    if (res > scnt / 2) abort();
    return res == scnt / 2;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &male, &female);
    if (absolute(male - female) != 1) {
        printf("-1"); return 0;
    }
    for (int i = 1; i <= n; i++) {
        char s[50];
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            Free[i][j] = s[j] == '.';
        }
    }
    scnt = 2 * max(male, female);
    for (int i = 1; i <= scnt; i++) {
        if (i == 1) {
            read(i, male < female);
        } else if (i <= male + 1) {
            read(i, true);
        } else {
            read(i, false);
        }
    }
    ll l = 0;
    ll R = 500000000000LL;
    while (l < R) {
        ll mid = (l + R) / 2;
        if (check(mid)) {
            R = mid;
        } else {
            l = mid + 1;
        }
    }
    if (!check(l)) {
        printf("-1");
    } else {
        printf("%lld", l);
    }
    return 0;
}