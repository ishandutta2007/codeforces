#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
#define M 200001
#define max(a,b) (a>b?a:b)

struct pnt {
    ll x, y;
    pnt(ll x=0, ll y=0):x(x), y(y){}
    pnt operator -(pnt a) { return pnt(x-a.x, y-a.y); }
    pnt operator +(pnt a) { return pnt(x+a.x, y+a.y); }
    pnt operator *(ll a) { return pnt(x*a, y*a); }
    pnt operator /(ll a) { return pnt(x/a, y/a); }
    ll operator ^(pnt a) { return x*a.y-y*a.x; }
    ll operator &(pnt a) { return x*a.x+y*a.y; }
    void input() { x=y=0, scanf("%I64d %I64d",&x,&y); }
    void print() { printf("%I64d %I64d\n",x,y); }
}q[M],con[M];


ll a[M],b[M],k,MX[M];


ll FABS(ll x) {
    if(x<0) return -x;return x;
}

bool cmp(pnt a, pnt b) {
    if (FABS(a.x-b.x)>0) return a.x<b.x;
    return a.y<b.y;
}

bool cmp1(pnt a, pnt b) {
    ll tmp=a-q[0]^b-q[0];
    if (FABS(tmp)>0) return tmp>0;
    ll u=a-q[0]&a-q[0], v=b-q[0]&b-q[0];
    return u<v;
}


struct dat{
    ll x,y;
    dat(ll x=0,ll y=0):x(x),y(y){}
}p[M];

bool cmp__(dat a,dat b) {
    if(a.x!=b.x) return a.x>b.x;
    return a.y>b.y;
}

int calc(ll x) {
    int st=0,en=k;
    while(en>st+1) {
        int mid=(en+st)/2;
        if(con[mid].x>=x) st=mid;
        else en=mid;
    }
    return st;
}

bool can(ll y,ll x) {
    if(con[1].x<=x) return 1;
    if(con[k-1].x>=x) return 1;
    int st=1,en=k-1;
    while(en>st+1) {
        int mid=(en+st)/2;
        if(con[mid].x>=x) st=mid;
        else en=mid;
    }
    ll X=con[st].x-x,XX=x-con[st+1].x;
    if(X*con[st+1].y+XX*con[st].y>(X+XX)*y) return 0;
    return 1;
}

ll n,m,x,y,cnt;

int main() {
    ///freopen("g.in","r",stdin);
    scanf("%I64d %I64d",&n,&m);
    scanf("%I64d %I64d",&x,&y);
    for(int i=0;i<n;i++) scanf("%I64d %I64d",&a[i],&b[i]);
    for(int i=0;i<m;i++) scanf("%I64d %I64d",&p[i].x,&p[i].y);
    sort(p,p+m,cmp__);
    int mx=-1;
    for(int i=0;i<m;i++) if(p[i].y>mx) {
        mx=p[i].y;
        q[cnt++]=pnt(p[i].x,p[i].y);
    }
    q[cnt++]=pnt(0,0);
    sort(q, q+cnt, cmp);
    sort(q+1, q+cnt, cmp1);
    k=0;
    for (int i=0; i<cnt; i++) {
        while (k>1 && (con[k-1]-con[k-2]^q[i]-con[k-2])<=0) k--;
        con[k++]=q[i];
    }
    for(int i=1;i<k;i++) MX[i]=max(MX[i-1],con[i].y);
    for(int i=0;i<n;i++) {
        int x=calc(a[i]+1);
        if(MX[x]>b[i]) continue;
        if(!can(b[i],a[i])) continue;
        return puts("Max");
    }
    return puts("Min");
}