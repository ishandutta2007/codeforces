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
int n,m;
int dp[4000010];
int suf[10000010];
int main(){
    n=read(),m=read();
    dp[n]=1;suf[n]=1;
    for(int i=n-1;i>=1;--i){
        dp[i]=suf[i+1];
        for(int j=2;1ll*j*i<=n;++j){
            (dp[i]+=(suf[j*i]-suf[j*(i+1)]+m)%m)%=m;
        }
        suf[i]=(suf[i+1]+dp[i])%m;
    }
    printf("%d\n",dp[1]);
}