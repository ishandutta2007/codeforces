#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fxaa
#define y0 fxbb
#define x1 fxcc
#define y1 fxdd
#define st first
#define nd second
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=1e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
struct node{
    int pos,x;
}p[1005];
bool cmp(node x,node y){return x.x<y.x;}
int a[1005][1005],n,m;
int lx[1005][1005],mx[1005],ly[1005][1005],my[1005];
int main(){
    scanf("%d%d",&n,&m);
    rep(i,n)rep(j,m)scanf("%d",a[i]+j);
    rep(i,n){
        rep(j,m)p[j]={j,a[i][j]};
        sort(p+1,p+m+1,cmp);
        int tmp=0;
        rep(j,m){
            if(p[j].x!=p[j-1].x)++tmp;
            lx[i][p[j].pos]=tmp;
        }
        mx[i]=tmp;
    }
    rep(j,m){
        rep(i,n)p[i]={i,a[i][j]};
        sort(p+1,p+n+1,cmp);
        int tmp=0;
        rep(i,n){
            if(p[i].x!=p[i-1].x)++tmp;
            ly[p[i].pos][j]=tmp;
        }
        my[j]=tmp;
    }
    //rep(i,n)rep(j,m)printf("%d %d %d %d\n",i,j,lx[i][j],ly[i][j]);
    //rep(i,n)printf("%d\n",mx[i]);
   // rep(j,m)printf("%d\n",my[j]);
    rep(i,n)rep(j,m)printf("%d%c",max(lx[i][j],ly[i][j])+max(mx[i]-lx[i][j],my[j]-ly[i][j])," \n"[j==m]);
    return 0;
}