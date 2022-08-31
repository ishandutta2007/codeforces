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
int a[N],b[N],n,k,m,s;
int la[N],cnt[N],tp[N],cur[N];
int main(){
    scanf("%d%d%d%d",&m,&k,&n,&s);
    int del=m-n*k;
    rep(i,m)scanf("%d",a+i);
    rep(i,s)scanf("%d",b+i),++cnt[b[i]];
    rep(i,5e5)tp[i]=m+1;
    for(int i=m;i;--i)la[i]=tp[a[i]],tp[a[i]]=i;
    la[m+1]=m+1;
    int low=1;
    rep(i,5e5)if(cnt[i]){
        cur[i]=tp[i];
        rep(j,cnt[i]-1)cur[i]=la[cur[i]];
        low=max(low,cur[i]);
    }
    rep(i,m){
        int c1=max(0,(low-i+1-k)),c2=(i-1)%k;
        if((i-1)/k>n)c2+=k*((i-1)/k-n);
        //printf("%d %d %d %d\n",i,low,c1,c2);
        if(c1+c2<=del&&low<=m){
            printf("%d\n",c1+c2);
            int tp2=c1+c2;
            for(int j=1;j<=c2;++j)printf("%d%c",j," \n"[(--tp2)==0]);
            for(int j=i;j<=low;++j)if(c1&&cnt[a[j]]==0)
                printf("%d%c",j," \n"[(--tp2)==0]),--c1;
            else --cnt[a[j]];
            return 0;
        }
        if(cnt[a[i]]){
            cur[a[i]]=la[cur[a[i]]];
            low=max(low,cur[a[i]]);
        }
    }
    puts("-1");
    return 0;

}