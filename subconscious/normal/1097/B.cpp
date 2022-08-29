#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuck
#define y0 fuxk
#define y1 fxck
#define x1 fxxk
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,inf=0x3f3f3f3f,MOD=998244353;
const ld eps=1e-9;
bool dp[20][360];int n;
int main(){
    dp[0][0]=1;
    scanf("%d",&n);
    rep(i,n){
        int x;scanf("%d",&x);
        for(int j=0;j<360;++j)dp[i][j]=dp[i-1][(j-x+360)%360]|dp[i-1][(j+x)%360];
    }
    puts(dp[n][0]?"YES":"NO");
}