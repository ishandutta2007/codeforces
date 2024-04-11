#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
    return f==-1?~x+1:x;
}
const int mod=998244353;
inline int qpow(int x,int k=mod-2){
    int res=1;
    while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
    return res;
}
int n,k;
int fac[100010],ifac[100010];
typedef vector<int>poly;
int x,len,R[300010];
void NTT(poly &s,int f){
    for(int i=0;i<x;++i) if(R[i]>i) swap(s[i],s[R[i]]);
    for(int l=1;l<x;l<<=1){
        int w;
        if(f==1) w=qpow(3,(mod-1)/(l<<1));
        else w=qpow(qpow(3),(mod-1)/(l<<1));
        for(int j=0;j<x;j+=(l<<1)){
            int sum=1;
            for(int k=0;k<l;++k){
                int a1=s[j+k],a2=1ll*s[j+k+l]*sum%mod;
                sum=1ll*sum*w%mod;
                s[j+k]=(a1+a2)%mod;s[j+k+l]=(a1-a2+mod)%mod;
            }
        }
    }
    if(f==-1){
        int t=qpow(x);
        for(int i=0;i<x;++i) s[i]=1ll*s[i]*t%mod;
    }
}
int main(){
    n=read(),k=read();
    fac[0]=1;
    for(int i=1;i<=k;++i) fac[i]=1ll*fac[i-1]*i%mod;
    ifac[k]=qpow(fac[k]);
    x=1,len=0;
    while(x<=k+k) x<<=1,++len;
    for(int i=0;i<x;++i) R[i]=(R[i>>1]>>1)|((i&1)<<len-1);
    for(int i=k-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
    poly A(x,0),B(x,0);
    for(int i=0;i<=k;++i) A[i]=ifac[i],B[i]=1ll*ifac[i]*qpow(i,k)%mod;
    for(int i=0;i<=k;++i){
        if(i&1) A[i]=mod-A[i];
    }
    NTT(A,1);NTT(B,1);
    for(int i=0;i<x;++i) A[i]=1ll*A[i]*B[i]%mod;
    NTT(A,-1);
    // for(int i=0;i<=k;++i) printf("%d ",A[i]);
    int bin=1;
    int ans=1ll*A[0]*qpow(n+1,n)%mod;
    for(int i=1;i<=n&&i<=k;++i){
        bin=1ll*bin*(n-i+1)%mod*qpow(i)%mod;
        (ans+=1ll*qpow(n+1,n-i)*fac[i]%mod*bin%mod*A[i]%mod)%=mod;
    }
    printf("%d\n",ans);
}