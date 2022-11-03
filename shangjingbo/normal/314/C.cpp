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

const int base = 1000000007;

const int maxm = 1000005;

int tree[maxm + 10], last[maxm];

const int maxn = 100005;

int f[maxn], pre[maxn], a[maxn];

inline void add(int x, int delta)
{
    for (;x <= maxm; x += lowbit(x)) {
        tree[x] += delta;
        if (tree[x] >= base) {
            tree[x] -= base;
        }
    }
}

inline int getsum(int x)
{
    int sum = 0;
    for (;x > 0; x -= lowbit(x)) {
        sum += tree[x];
        if (sum >= base) {
            sum -= base;
        }
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
        ++ a[i];
        pre[i] = last[a[i]];
        last[a[i]] = i;
    }
    add(1, 1);
    for (int i = 0; i < n; ++ i) {
        f[i] = (long long)getsum(a[i]) * (a[i] - 1) % base;
        if (pre[i] != -1) {
/*          f[i] -= f[pre[i]];
            if (f[i] < 0) {
                f[i] += base;
            }*/
            add(a[pre[i]], (base - f[pre[i]]) % base);
            f[pre[i]] = 0;
        }
        add(a[i], f[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
//printf("%d ", f[i]);
        ans += f[i];
        ans %= base;
    }
//puts("");
    printf("%d\n", ans);
    return 0;
}