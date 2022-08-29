#include<cstdio>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=j;i<=(int)k;i++)
#define per(i,j,k) for(int i=j;i>=(int)k;i--)
#define For(i,j,k) for(int i=j;i<k;i++)
using namespace std;
typedef long long LL;
const int jsb=1000000007;
const int MAXN=2100000;
inline int Pow(int a,int b){
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%jsb)
    if(b&1)c=c*1ll*a%jsb;
    return c;
}
int fac[MAXN],inv[MAXN];
inline void init(){
    fac[0]=1;
    rep(i,1,2000000)fac[i]=fac[i-1]*1ll*i%jsb;
    inv[2000000]=Pow(fac[2000000],jsb-2);
    per(i,1999999,0)inv[i]=inv[i+1]*1ll*(i+1)%jsb;
}
inline int factor(int l,int r){
    return fac[r]*1ll*inv[l-1]%jsb;
}
inline int wan(int a,int b){ // point :a color:b
    if(a>b)return 0;
    return factor(b-a+1,b);
}   
inline int work(int n,int co,int w){ //For len=n,wei<=w
    if(w>n/2){
        int ret=wan(n-w,co);
        ret=ret*1ll*ret%jsb;
        int fre=n-(n-w)*2;
        ret=ret*1ll*Pow(co,fre)%jsb;
        return ret;
    }
    else{
        int tuan=n-w;
        int ch=tuan*2-n;
        int ret=wan(tuan-ch,co);
        if(co<tuan)return 0;
        ret=ret*1ll*factor(co-tuan+1,co-tuan+ch)%jsb;
        ret=ret*1ll*factor(co-tuan+1,co-ch)%jsb;
        return ret;
    }
}
int wannow;int fat=0;
inline int go(int n,int k,int w){
    int ret=wannow;
    ret=ret*1ll*ret%jsb;
    int fre=(n-(n-w)*2)%(jsb-1);
    ret=ret*1ll*fat%jsb;
    return ret;
}
inline int Getans(int start,int k,int w){
    int res=0;
    if(w<=k){
        for(int i=start;i<=w+k;i++)
        res=(res+work(i,k,w))%jsb;
        return res;
    }
    wannow=fac[k]*1ll*inv[k-start+w]%jsb;
    fat=Pow(k,2*w-start);int nik=Pow(k,jsb-2);
    rep(i,start,w+k){
        res=(res+go(i,k,w))%jsb;
        wannow=wannow*1ll*(k-i+w)%jsb;
        fat=fat*1ll*nik%jsb;
    }
    return res;
}
int main(){
    int k,w;init();
    scanf("%d%d",&k,&w);
    if(w<=k){
        int ans=0;
        for(int i=w;i<=w+k;i++){
            ans=(ans+work(i,k,w))%jsb;
            ans=(ans-work(i,k,w-1))%jsb;
        }
        printf("%d\n",(ans+jsb)%jsb);   
    }
    else{
        int ans=Getans(w,k,w);
        ans=(ans-Getans(w,k,w-1))%jsb;
        printf("%d\n",(ans+jsb)%jsb);
    }
    return 0;
}