#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
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
typedef vector<int> vi;
const int N=3e6+5,mod=1e9+7;
char s[2][N];
int T,n;
int dp[4],tmp[4];
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        scanf("%s",s[0]+1);
        scanf("%s",s[1]+1);
        dp[0]=0;dp[1]=dp[2]=dp[3]=-mod;
        //puts("FUCK");
        rep(i,n){
            int mk=0;
            if(s[0][i]=='0'||s[1][i]=='0')mk|=1;
            if(s[0][i]=='1'||s[1][i]=='1')mk|=2;
            for(int j=0;j<4;++j)
                tmp[j]=dp[j];
            for(int j=0;j<4;++j)
                tmp[j|mk]=max(tmp[j|mk],dp[j]);
            tmp[0]=max(tmp[0],max(tmp[1]+1,max(tmp[2]+0,tmp[3]+2)));
            for(int j=0;j<4;++j)
                dp[j]=tmp[j];
            //printf("%d %d %d %d\n",dp[0],dp[1],dp[2],dp[3]);
        }
        printf("%d\n",dp[0]);
    }

    return 0;
}
/*
XFOF.XFOFX
XFOFXFOF
6+10+12
9+7
*/