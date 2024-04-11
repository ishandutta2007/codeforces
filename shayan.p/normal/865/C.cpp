// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef pair<ld,ld> pld;

const int maxn=52,maxt=5e3+10;
const ll inf=1e18;

ld dp[maxn][maxt],X;
int a[maxn],b[maxn],p[maxn],n,r;

ld solve(){
    for(int i=0;i<=r;i++)
	dp[n][i]=i;
    for(int i=r+1;i<maxt;i++)
	dp[n][i]=X+i;
    for(int i=n-1;i>=0;i--)
	for(int j=0;j<maxt;j++)
	    dp[i][j]=min(X+j,(ld(p[i])/100)*(j+a[i]>=maxt?inf:dp[i+1][j+a[i]])+(ld(100-p[i])/100)*(j+b[i]>=maxt?inf:dp[i+1][j+b[i]]));
    return dp[0][0];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>r;
    for(int i=0;i<n;i++)
	cin>>a[i]>>b[i]>>p[i];
    ld L=0,R=inf;
    for(int test=0;test<=200;test++){
	ld mid=(L+R)/2;
	X=mid;
	if(solve()==mid)
	    L=mid;
	else
	    R=mid;
    }
    cout<<setprecision(15)<<fixed<<L<<endl;
    return 0;
}