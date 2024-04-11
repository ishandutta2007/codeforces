#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int P=1000000007;
const int N=100005;
inline int Pow(int a,int b){
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
    return c;
}
int p[N],miu[N];
int n,a[N];
int cnt[N];
const int S=100000;
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,n)cnt[a[i]]++;

    rep(i,2,S)if(!p[i])for(int j=i;j<=S;j+=i)if(!p[j])p[j]=i;
    miu[1]=1;
    rep(i,2,S)if((i/p[i])%p[i]==0)miu[i]=0;else miu[i]=P-miu[i/p[i]];
    int ans=0;
    rep(i,1,S){
        int w=0;
        for(int j=i;j<=S;j+=i)w+=cnt[j];
        ans=(ans+(Pow(2,w)-1)*1ll*miu[i])%P;
    }
    printf("%d\n",ans);
    return 0;
}