#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double _x,double _y){x=_x;y=_y;}
    inline void read(){scanf("%lf%lf",&x,&y);}
    inline void show(){printf("%lf %lf\n",x,y);}
    inline double norm(){ return sqrt( sqr(x)+sqr(y) ); }
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x+b.x,a.y+b.y); }
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x-b.x,a.y-b.y); }
inline Tpoint operator *(const Tpoint &a,const double &b){ return Tpoint(a.x*b,a.y*b); }
inline Tpoint operator /(const Tpoint &a,const double &b){ return Tpoint(a.x/b,a.y/b); }
inline double det(const Tpoint &a,const Tpoint &b){ return a.x*b.y-a.y*b.x; }
inline double dot(const Tpoint &a,const Tpoint &b){ return a.x*b.x+a.y*b.y; }
//=============================================================================================

const ULL magic =   37;
const int maxn  =   100005;

ULL h[maxn],pw[maxn];
char s[maxn];

inline int compare(int i,int j,int x,int y)
{
    int l=0,r=min(j-i+1,y-x+1)+1;
    while (l+1<r){
        int mid=(l+r)>>1;
        if (h[i+mid]-h[i]*pw[mid]==h[x+mid]-h[x]*pw[mid]){
            l=mid;
        }else r=mid;
    }
    
    if (i+l>j){
        if (x+l>y) return 0;
        return -1;
    }
    if (x+l>y) return 1;
    
    if (s[x+l]==s[i+l]) return 0;
    if (s[x+l]>s[i+l]) return -1;
    return 1;
}

struct node
{
    int l,r;
    node(){}
    node(int a,int b){l=a;r=b;}
};

priority_queue<node> heap;
int n;

inline bool operator<(const node &a,const node &b)
{
    int res=compare(a.l,a.r,b.l,b.r);
//printf("%d %d %d %d %d\n",a.l,a.r,b.l,b.r,res);
    return res==1 || res==0 && a.l>b.l;
}

int main()
{
    //freopen("input.txt","r",stdin);
    
    scanf("%s",s);
    n=strlen(s);
    for (int i=0;i<n;++i)
        h[i+1]=h[i]*magic+s[i]-'a'+1;
    pw[0]=1;
    for (int i=1;i<=n;++i)
        pw[i]=pw[i-1]*magic;
    
    for (int i=0;i<n;++i)
        heap.push(node(i,i));
//printf("%d\n",compare(1,1,2,2));
    
    int k;
    scanf("%d",&k);
    while (--k && heap.size()){
        node u=heap.top();
        //printf("%d %d\n",u.l,u.r);
        heap.pop();
        if (u.r+1<n){
            ++u.r;
            heap.push(u);
        }
    }
    
    if (heap.size()){
        node u=heap.top();
        heap.pop();
        for (int i=u.l;i<=u.r;++i)
            printf("%c",s[i]);
        puts("");
    }else puts("No such line.");
    
    //printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
    
    return 0;
}