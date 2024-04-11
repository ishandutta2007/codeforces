#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=25,mod=31607;
const ld eps=1e-10;
int a[N][N],n;
int pw(int x,int y=mod-2){
    int s=1;
    for(;y;y>>=1,x=(ll)x*x%mod)
        if(y&1)s=(ll)s*x%mod;
    return s;
}
const int MX=(1<<23)+5;
int r10e4,s[MX],tmp[MX],is[MX];

void UFWT(int *a, int n) {
    for(int d=1;d<n;d<<=1)for(int m=d<<1,i=0;i<n;i+=m)for(int j=0;j<d;++j){
                int x = a[i + j], y = a[i + j + d];
                a[i + j] = (x - y+mod)%mod;
            }
}

int main(){
    for(int i=0;i<=23;++i)is[1<<i]=i;
    r10e4=pw(10000);
    scanf("%d",&n);
    rep(i,n)rep(j,n)scanf("%d",a[i]+j),a[i][j]=a[i][j]*r10e4%mod;
    
    //rep(i,n){rep(j,n)printf("%d ",a[i][j]);puts("");}
    
    for(int mk=(1<<(n+2))-1;~mk;--mk)s[mk]=1;
    rep(i,n){
        int al=1;
        rep(j,n)al=al*a[i][j]%mod;
        int u=i,v=n-i+1;
        tmp[0]=1;
        for(int mk=1;mk<1<<n;++mk){
            int cg=mk-(mk&(mk-1));
            tmp[mk]=tmp[mk^cg]*a[i][is[cg]+1]%mod;
        }
        for(int mk=0;mk<1<<n;++mk)
            tmp[mk]=(tmp[mk]-al+mod)%mod;
        for(int mk=0;mk<1<<(n+2);++mk){
            int tmk=mk&((1<<n)-1);
            if(mk&(1<<(n)))tmk|=(1<<(u-1));
            if(mk&(1<<(n+1)))tmk|=(1<<(v-1));
            s[mk]=s[mk]*tmp[tmk]%mod;
        }

        //UFWT(s,1<<(n+2));
        //for(int i=0;i<1<<(n+2);++i)printf("%d %d\n",i,s[i]);
        //FWT(s,1<<(n+2));
    }
    UFWT(s,1<<(n+2));
    //for(int i=0;i<1<<(n+2);++i)printf("%d %d\n",i,s[i]);
    int ans=(1-s[0]+mod)%mod;
    printf("%d\n",ans);
    return 0;
}
/*
*/