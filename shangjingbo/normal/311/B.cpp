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

const long long inf = 1000000000000000000LL;

const int maxp = 101;
const int maxn = 100001;

int n, m, p, d[maxn], a[maxn];
long long sum[maxn], f[maxp][maxn];

struct node
{
    long long k, b;
    node(LL k, LL b): k(k), b(b) {
    }
    
    long long test(long long x) {
        return k * x + b;
    }
};

long double cross(const node &a, const node &b) 
{
    return ((long double)a.b - b.b) / ((long double)b.k - a.k);
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    if (p >= m) {
        puts("0");
        return 0;
    }
    d[0] = 0;
    for (int i = 1; i < n; ++ i) {
        int x;
        scanf("%d", &x);
        d[i] = d[i - 1] + x;
    }
    for (int i = 0; i < m; ++ i) {
        int h, t;
        scanf("%d%d", &h ,&t);
        -- h;
        a[i] = t - d[h];
    }
    sort(a, a + m);
    for (int i = 0; i < m; ++ i) {
        //printf("%d\n", a[i]);
        sum[i + 1] = sum[i] + a[i];
    }
    
    for (int i = 0; i <= m; ++ i) {
        f[0][i] = inf;
    }
    f[0][0] = 0;
    for (int i = 1; i <= p; ++ i) {
        deque<node> q;
        f[i][0] = inf;
        for (int j = 0; j < m; ++ j) {
            f[i][j + 1] = inf;
            if (f[i - 1][j] != inf) {
                node cur(-j, f[i - 1][j] + sum[j]);
                while (q.size() >= 2 && cross(q[q.size() - 2], q[q.size() - 1]) > cross(q[q.size() - 2], cur)) {
                    q.pop_back();
                }
                q.push_back(cur);
            }
            while (q.size() >= 2 && q[0].test(a[j]) > q[1].test(a[j])) {
                q.pop_front();
            }
            if (q.size()) {
                f[i][j + 1] = q[0].test(a[j]) + a[j] * (long long)(j + 1) - sum[j + 1];
            }
            /*for (int k = 0; k <= j; ++ k) {
                if (f[i - 1][k] != inf) {
                    f[i][j + 1] = min(f[i][j + 1], f[i - 1][k] + a[j] * (long long)(j - k + 1) - (sum[j + 1] - sum[k]));
                }
            }*/
            /*if (f[i][j] != inf) {
                printf("%d %d %I64d\n", i, j, f[i][j]);
            }*/
        }
    }
    
    printf("%I64d\n", f[p][m]);
    
    return 0;
}