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
char s[N];
int n;
ll dp[2][11][11];
ll ans;
inline int calc(int x,int y){
    y%=11;
    return ((x+x+y-1)*y/2)%11;
}
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    memset(dp,0,sizeof dp);int r=0;
    rep(cc,n){
        r^=1;memset(dp[r],0,sizeof dp[r]);
        int now=s[cc]-'0';
        for(int i=0;i<11;++i)
            for(int j=0;j<11;++j)
                if(now<i)
                dp[r][(i+j+now+1)%11][(calc((i+1)%11,j+now)+i-1-now)%11]+=dp[r^1][i][j];
        if(now!=0)++dp[r][now][(9-now+calc(1,now-1))%11];
        
        for(int i=0;i<11;++i)
            for(int j=0;j<11;++j)
                ans+=dp[r][i][j];
    }

    printf("%lld\n",ans);
    return 0;
}