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

const int maxn = 105;
const int maxlen = 40;

pair<int, long long> f[maxn][maxn][maxlen + 1];
int n, m, b, d;
char a[maxn * 2], c[maxn];

inline bool check(int t)
{
    t *= m;
    int i = 0, j = 0;
    long long step = 0;
    for (int len = 0; (1LL << len) <= t && step <= b; ++ len) {
        if (t >> len & 1) {
            step += f[i][j][len].second;
            i = f[i][j][len].first;
            if (i == -1) {
                return false;
            }
            j = (j + (1LL << len) % m) % m;
        }
    }
//printf("check: %d %I64d\n", t, step);
    return step <= b;
}

int main()
{
    scanf("%d%d", &b, &d);
    scanf("%s%s", a, c);
    
    n = strlen(a), m = strlen(c);
    for (int i = 0; i < n; ++ i) {
        a[i + n] = a[i];
    }
    
    memset(f, -1, sizeof(f));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            for (int k = 0; k < n; ++ k) {
                if (a[i + k] == c[j]) {
                    f[i][j][0] = MP((i + k + 1) % n, (i == 0) + ((i + k) >= n));
//printf("%d %d %d: %d %I64d\n", i, j, k, f[i][j][0].first, f[i][j][0].second);
                    break;
                }
            }
        }
    }
    for (int len = 0; len < maxlen; ++ len) {
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (f[i][j][len].first != -1) {
                    int ni = f[i][j][len].first;
                    int nj = (j + (1LL << len) % m) % m;
                    if (f[ni][nj][len].first == -1) {
                        continue;
                    }
                    f[i][j][len + 1] = MP(f[ni][nj][len].first, f[i][j][len].second + f[ni][nj][len].second);
                    f[i][j][len + 1].second = min(f[i][j][len + 1].second, 10000000000000LL);
//printf("%d %d %d: %d %I64d\n", i, j, len + 1, f[i][j][len + 1].first, f[i][j][len + 1].second);
                }
            }
        }
    }
    
    int l = 0, r = n * b / m + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l / d);
    
    return 0;
}