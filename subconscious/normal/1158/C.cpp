#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define eb emplace_back
#define mp make_pair
#define st first
#define nd second
#define x0 fxxk
#define y0 fxck
#define x1 fuxk
#define y1 fucx
using namespace std;
using ll=long long;
using ld=long double;
using pr=pair<int,int>;
constexpr int N=2e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
struct node{
    int x,y;
}a[N],sta[N];
bool cmp(node p,node q){
    if(p.y!=q.y)return p.y>q.y;
    return p.x<q.x;
}
int ans[N],n,T,nm;
bool sol(){
    int top=0,num=n+1;
    rep(i,n)ans[i]=-1;
    rep(i,nm){
        if(a[i].y!=n+1&&ans[a[i].y]==-1)ans[a[i].y]=--num;
        ans[a[i].x]=--num;
        while(top>0&&a[i].y<=sta[top].x)--top;
        if(top==0||(sta[top].x<=a[i].x&&a[i].y<=sta[top].y))
            sta[++top]=a[i];
        else return 0;
    }
    rep(i,n)if(ans[i]==-1)ans[i]=--num;
    return 1;
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);nm=0;
        rep(i,n){
            int x;
            scanf("%d",&x);
            if(x!=-1)a[++nm]={i,x};
        }
        if(nm>1)sort(a+1,a+nm+1,cmp);
        if(sol())rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
        else puts("-1");
    }
    return 0;
}