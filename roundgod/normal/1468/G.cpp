#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
const int maxn=1e6+20;
int n;
struct point{
    ll x,y;
    point operator-(const point &u){
        return (point){x-u.x,y-u.y};
    }
}a[maxn],o,r,p;
db H;
struct line{
    point a,b;
};
ll mult(point a,point b){
    return a.x*b.y-b.x*a.y;
}
db sqr(db x){return x*x;}
db dis(point u,point v){
    return sqrt(sqr(u.x-v.x)+sqr(u.y-v.y));
}
db intersection(line u,line v){
    db x=u.a.x,y=u.a.y;
    double t=(double)((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
            /((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    x+=t*(u.b.x-u.a.x);
    y+=t*(u.b.y-u.a.y);
    return sqrt(sqr(x-v.b.x)+sqr(y-v.b.y));
}

int main(){
    scanf("%d%lf",&n,&H);
    for (int i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
    o.x=a[n].x; o.y=a[n].y+H;
    p=a[n];
    db ans=0;
    for (int i=n;i>1;i--){
        ll res=mult(o-p,o-a[i-1]);
        if (res<0){
            ans+=intersection((line){o,p},(line){a[i],a[i-1]});
            p=a[i-1];
        } else if (res==0){
            if (p.x==a[i].x&&p.y==a[i].y) ans+=sqrt(sqr(a[i].x-a[i-1].x)+sqr(a[i].y-a[i-1].y));
            p=a[i-1];
        }
        //printf("%lld %lld %.10f\n",p.x,p.y,ans);
    }
    printf("%.10f\n",ans);
    return 0;
}