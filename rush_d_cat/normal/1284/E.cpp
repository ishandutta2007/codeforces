#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=5002;
typedef long long LL;
typedef long long ll;
int n;
LL X[N],Y[N],x[N],y[N],m;
const int  maxn=5000+50;
const double eps=1e-8;
const double PI=acos(-1.0);
struct point
{
    ll x,y;
    point(ll x=0,ll y=0):x(x),y(y) {}
    point operator - (const point &t)const
    {
        return point(x-t.x,y-t.y);
    }
    ll operator * (const point &t)const  ///  : 
    {
        return x*t.y-y*t.x;
    }
    ll operator ^ (const point &t)const  ///  : 
    {
        return x*t.x+y*t.y;
    }
    bool operator < (const point &t)const  /// 
    {
        bool up[2]= {0,0};
        if(y>0 || (y==0 && x>0)) up[0]=1;
        if(t.y>0 || (t.y==0 && t.x>0)) up[1]=1;
        if(up[0]^up[1]) return up[0];
        return (*this)*t ? (*this)*t>0 : ((*this)^(*this))<(t^t);
    }
};
 
point p[maxn],v[maxn*2];
/*
int main()
{
 
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
            scanf("%lld%lld",&p[i].x,&p[i].y);
        ll ans=1LL*n*(n-1)*(n-2)/6,tmp=0;
        for(int i=1; i<=n; i++)
        {
            int cun=0;
            for(int j=1; j<=n; j++)
            {
                if(i==j) continue;
                v[++cun]=p[j]-p[i]; /// i->j
            }
            sort(v+1,v+1+cun);
            for(int j=1; j<=cun; j++) v[j+cun]=v[j];
 
            ///->,2
            for(int j=2; j<=cun; j++)
            {
                ll num=0;
                while(j<=cun&&v[j-1]*v[j]==0 && (v[j-1]^v[j])>0)
                    j++,num++;
                    num++;
                    tmp+=num*(num-1)/2;
            }
            int p1=1,p2=1;
            for(int j=1; j<=cun; j++)
            {
                while(p1<=j || (p1<j+cun && v[p1]*v[j]<0 && (v[p1]^v[j])>0)) p1++;/// v[j]
                while(p2<=j || (p2<j+cun && v[p2]*v[j]<0))p2++;/// v[j]++
                ans-=p2-p1;
            }
        }
        printf("%lld\n",ans-tmp/2);
    }
    return 0;
}
*/
LL cac(){
    sort(v+1,v+1+m);
    for(int i=1;i<=m;i++) v[i+m]=v[i];
    for(int i=1;i<=m;i++){
        //printf("(%lld, %lld)\n", v[i].x, v[i].y);
    }
    ll ans=0;
    //printf("#### %lld\n", v[1]*v[1]);
    for(int i=1,j=2;i<=m;i++) {
        if(i==j) ++j;
        while(j<i+m && (v[i]*v[j])>0 ) ++j;
        // [i,j)
        //printf("[%d, %d)\n", i,j);
        ll c=j-i-1;
        ans=ans+c*(c-1)*(c-2)/6;
    }
    //printf("%lld\n", ans);
    return (LL)(n-1)*(n-2)*(n-3)*(n-4)/24 - ans;;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&X[i],&Y[i]);
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        m=0;
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            v[++m]=point(X[j]-X[i], Y[j]-Y[i]);
        }
        ans+=cac();
        //printf("----------------\n");
    }
    cout<<ans<<endl;
}