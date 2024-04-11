#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define foru(i,a,b) for(i=(a);i<=(b);i++)
#define ford(i,a,b) for(i=(a);i>=(b);i--)

#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))
#define MP make_pair
#define PB push_back

typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
typedef unsigned long long ULL;

const double pi=acos(-1.0);
const double eps=1e-8;
//==============================================
#define maxn 100005
#define maxm 25

struct point{
    int x,y;
    point(int x=0,int y=0):x(x),y(y){}
    void get(){scanf("%d%d",&x,&y);}
    void show(){printf("%dlf %d\n",x,y);}
    double dis(){return sqrt((double)x*x+(double)y*y);}
}a[maxn*2],b[maxm];
int n,m;
int Left[maxn],Right[maxn];
long long sum[maxn*2];

inline point operator+(const point &a,const point &b){return point(a.x+b.x,a.y+b.y);}
inline point operator-(const point &a,const point &b){return point(a.x-b.x,a.y-b.y);}

inline long long det(const point &a,const point &b)
{
    return (long long)a.x*b.y-(long long)a.y*b.x;
}

inline bool checkRight(int i,const point &x,const point &y)
{
    if (det(b[i]-x,y-x)<=0) return false;
    return true;
}

struct node
{
    point p;
    double key;
}c[maxn*2];

inline bool cmp(const node &a,const node &b)
{
    return a.key+eps<b.key;
}

inline long long C2(long long n)
{
    return n*(n-1)/2;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        a[i].get();
    a[n]=a[0];
    
    scanf("%d",&m);
    for (int i=0;i<m;++i)
        b[i].get();

    for (int type=0;type<m;++type)
    {
        bool in=true;
        for (int i=0;i<n && in;++i)
        if (!checkRight(type,a[i],a[i+1])) in=false;
        
        if (!in)
        {
            puts("0");
            continue;
        }
        
        for (int i=0;i<n;++i)
        {
            c[i].p=a[i]-b[type];
            c[i].key=atan2( c[i].p.y,c[i].p.x );
        }
        
        sort(c,c+n,cmp);
        
        for (int i=0;i<n;++i)
            c[i+n]=c[i];
        
        long long ans=n*(long long)(n-1)*(n-2)/6;
        for (int i=0,j=0;i<n;++i)
        {
            if (j<=i) j=i+1;
            while (det(c[i].p,c[j].p)>0) ++j;
            
            ans-=C2(j-i-1);
        }
        
        cout << ans << endl;
    }
    
    return 0;
}