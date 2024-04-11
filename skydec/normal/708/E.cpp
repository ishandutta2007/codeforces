#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
const int P=1000000007;
inline int Pow(int a,int b){
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
    return c;
}
inline void add(int &a,int b){a+=b;if(a>=P)a-=P;}
inline void dec(int &a,int b){a-=b;if(a<0)a+=P;}
int fac[N],inv[N],n,k,_a,_b,m,p;
int h[N];
inline int C(int a,int b){
    if(a<b)return 0;
    return (fac[a]*1ll*inv[b]%P)*1ll*inv[a-b]%P;
}
void init(int n){
    fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*1ll*i%P;
    inv[n]=Pow(fac[n],P-2);per(i,n-1,0)inv[i]=inv[i+1]*1ll*(i+1)%P;
}
const int M=1505;
int fL[M][M],fR[M][M];
int all=0;
int sumh[M];
int tmp[M];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d",&_a,&_b);
    p=_a*1ll*Pow(_b,P-2)%P;
    scanf("%d",&k);
    init(k);
    rep(i,0,m){
        if(i<=k){
            h[i]=C(k,i);
            h[i]=h[i]*1ll*Pow(p,i)%P;
            h[i]=h[i]*1ll*Pow((P+1-p)%P,k-i)%P;
        }
        sumh[i]=h[i];
        if(i)add(sumh[i],sumh[i-1]);
    }
    rep(i,1,m)rep(j,i,m){
        add(fL[1][i],h[i-1]*1ll*h[m-j]%P);
        add(fR[1][j],h[i-1]*1ll*h[m-j]%P);
    }
    rep(i,2,n){
        int res=0;
        rep(j,1,m)add(res,fR[i-1][j]);
        rep(j,1,m)add(fL[i][j],fL[1][j]*1ll*res%P);
        rep(j,1,m)add(fR[i][j],fR[1][j]*1ll*res%P);

        memset(tmp,0,sizeof tmp);
        res=0;
        rep(j,1,m){
            dec(fL[i][j],(res*1ll*sumh[m-j]%P)*1ll*h[j-1]%P);
            add(tmp[j],res*1ll*h[j-1]%P);
            add(res,fR[i-1][j]);
        }
        rep(j,1,m)add(tmp[j],tmp[j-1]);
        rep(j,1,m)dec(fR[i][j],h[m-j]*1ll*tmp[j]%P);

        memset(tmp,0,sizeof tmp);
        res=0;
        per(j,m,1){
            dec(fR[i][j],(res*1ll*sumh[j-1]%P)*1ll*h[m-j]%P);
            add(tmp[j],res*1ll*h[m-j]%P);
            add(res,fL[i-1][j]);
        }
        per(j,m-1,0)add(tmp[j],tmp[j+1]);
        rep(j,1,m)dec(fL[i][j],h[j-1]*1ll*tmp[j]%P);
    }
    //rep(i,1,n)rep(j,1,m){
    //    printf("fL[%d][%d]=%d\n",i,j,fL[i][j]);
    //    printf("fR[%d][%d]=%d\n",i,j,fR[i][j]);
    //}
    int ans=0;
    rep(i,1,m)add(ans,fR[n][i]);
    printf("%d\n",ans);
    return 0;
}