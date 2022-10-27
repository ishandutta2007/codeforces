#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define rd(x) scanf("%d",&x)
#define prt(x) printf("%d\n", x);
#define prtvec(v) for(int i=0;i<v.size();i++) printf("%d%c", v[i], i==(v.size()-1)?'\n':' ');
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,y,x) for(int i=y;i>=x;i--)
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
const int N=1000000+10;
const double EPS = 1e-8;
int n,x,y,a[N];
const LL INF=1e18;

vector<int> fac(int x) {
    vector<int> ret;
    for(int i=2;i*i<=x;i++) {
        if(x%i==0) ret.pb(i);
        while(x%i==0) x/=i;
    }
    if(x>1) ret.pb(x);
    return ret;
}
LL dp[N][4];
void init() {
    rep(i,1,n) rep(j,0,2) dp[i][j]=INF;
}
LL cac(int i, int g) {
    if(a[i]%g==0) return 0;
    if((a[i]-1)%g==0 || (a[i]+1)%g==0) return x;
    return INF;
}
LL getAns(int g) {
    //printf("g = %d\n", g);
    init(); dp[1][0]=0;    
    rep(i,2,n) {
        dp[i][0]=min(dp[i-1][0]+cac(i,g), dp[i][0]);
        dp[i][1]=min(dp[i-1][0]+y, dp[i][1]);
        dp[i][1]=min(dp[i-1][1]+y, dp[i][1]);
        dp[i][2]=min(dp[i-1][1]+cac(i,g), dp[i][2]);
        dp[i][2]=min(dp[i-1][2]+cac(i,g), dp[i][2]);
    }
    LL ans=min(min(dp[n][0],dp[n][1]),dp[n][2]);
    return ans;
}
LL solve(){
    LL ret=INF;
    init();
    vector<int> vec = fac(a[1]);
    rep(i,0,sz(vec)-1){
        ret=min(ret,getAns(vec[i]));
    }

    vec=fac(a[1]-1);
    rep(i,0,sz(vec)-1){
        ret=min(ret,getAns(vec[i])+x);
    }

    vec=fac(a[1]+1);
    rep(i,0,sz(vec)-1){
        ret=min(ret,getAns(vec[i])+x);
    }    
    return ret;
}
int main(){

    rd(n); rd(x); rd(y); swap(x,y);
    rep(i,1,n) rd(a[i]);
    LL ret = solve();
    rep(i,1,n) if(i<n-i+1) swap(a[i],a[n+1-i]);
    ret = min(ret, solve());
    cout << ret << endl;

}