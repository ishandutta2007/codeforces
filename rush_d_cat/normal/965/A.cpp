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
const int MOD=1000000007;
const int N=200000+10;
const double EPS = 1e-8;
LL n,k,s,p;
int main(){
    cin>>k>>n>>s>>p;
    LL x=(n+s-1)/s;
    x = x*k;
    LL ans = (x+p-1) / p;
    cout<<ans<<endl;
}