#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
using namespace std;

#define PB push_back
#define MP make_pair

#define FOR(it,a) for (__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

inline int sign(double x)
{
    if (x<-eps) return -1;
    return x>eps;
}

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double x,double y):x(x),y(y){}
    inline double norm(){return sqrt(x*x+y*y);}
    inline void rotate(double ang)
    {
        double co=cos(ang),si=sin(ang);
        double tx=x,ty=y;
        x=tx*co-ty*si;
        y=tx*si+ty*co;
    }
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){return Tpoint(a.x+b.x,a.y+b.y);}
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){return Tpoint(a.x-b.x,a.y-b.y);}
inline Tpoint operator *(const Tpoint &a,const double &b){return Tpoint(a.x*b,a.y*b);}
inline Tpoint operator /(const Tpoint &a,const double &b){return Tpoint(a.x/b,a.y/b);}
inline double det(const Tpoint &a,const Tpoint &b){return a.x*b.y-a.y*b.x;}
inline double dot(const Tpoint &a,const Tpoint &b){return a.x*b.x+a.y*b.y;}
//================================

const int maxn = 100005;

int oper[maxn], operand[maxn][2];
vector<LL> candidate;
LL a[maxn];
int c[maxn], n;

vector< pair<int, long long> > adj[maxn];
long long dist[maxn];
bool vis[maxn];

inline bool relax(LL &a, LL b)
{
    if (a == -1 || a > b) {
        a = b;
        return true;
    }
    return false;
}

inline void process(int l, int r)
{
    for (int i = 0; i < candidate[0]; ++ i) {
        adj[i].clear();
        dist[i] = -1;
        vis[i] = false;
        for (int j = 1; j < candidate.size(); ++ j) {
            long long x = i + candidate[j];
            adj[i].push_back(make_pair(x % candidate[0], x / candidate[0]));
        }
    }
    int src = 1 % candidate[0];
    dist[src] = 0;
    vis[src] = true;
    queue<int> q;
    q.push(src);
    while (q.size()) {
        int u = q.front();
        vis[u] = false;
        q.pop();
        FOR (edge, adj[u]) {
            int v = edge->first;
            long long d = dist[u] + edge->second;
            if (relax(dist[v], d)) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    
    multiset<PII> h;
    for (int i = 0; i < n; ++ i) {
        if (c[i] <= 0) {
            continue;
        }
        int x = a[i] % candidate[0];
        if (dist[x] == -1 || dist[x] > a[i] / candidate[0]) {
            vis[i] = false;
        } else {
            vis[i] = true;
        }
        if (vis[i]) {
            h.insert(make_pair(c[i], -i));
        }
    }
    multiset<PII>::iterator it;
    for (int i = l; i < r; ++ i) {
        if (oper[i] == 3) {
            int answer;
            if (h.size() == 0) {
                answer = 0;
            } else {
                it = h.end();
                -- it;
                answer = it->first;
                c[-it->second] = 0;
                h.erase(it);
            }
            printf("%d\n", answer);
        } else if (oper[i] == 2) {
            int x = operand[i][0];
            int y = operand[i][1];
            -- x;
            if (vis[x]) {
                it = h.lower_bound(make_pair(c[x], -x));
                h.erase(it);
            }
            c[x] -= y;
            if (vis[x]) {
                h.insert(make_pair(c[x], -x));
            }
        }
    }
}

int main()
{
    long long h, k;
    int m;
    scanf("%I64d%d%d%I64d", &h, &n, &m, &k);
    candidate.push_back(k);
    for (int i = 0; i < n; ++ i) {
        scanf("%I64d%d", &a[i], &c[i]);
        vis[i] = false;
    }
    int last = -1;
    for (int i = 0; i < m; ++ i) {
        scanf("%d", &oper[i]);
        if (oper[i] == 1) {
            process(last + 1, i);
            last = i;
            scanf("%I64d", &k);
            candidate.push_back(k);
        } else if (oper[i] == 2) {
            scanf("%d%d", &operand[i][0], &operand[i][1]);
        }
    }
    process(last + 1, m);
    return 0;
}