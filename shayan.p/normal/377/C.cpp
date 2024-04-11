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

const int maxn=102,maxm=22,maxt=(1<<20)+10,inf=1e9;

char ch[maxm];
int a[maxn],b[maxm],dp[2][maxt];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)
	cin>>a[i];
    sort(a,a+n,greater<int>());
    int m;cin>>m;
    for(int q=0;q<m;q++){
	cin>>ch[q]>>b[q];
    }
    for(int q=m-1;q>=0;q--){
	if(b[q]==1) fill(dp[q&1],dp[q&1]+maxt,-inf);
	if(b[q]==2) fill(dp[q&1],dp[q&1]+maxt, inf);
	for(int msk=0;msk<(1<<m);msk++){
	    if(m-__builtin_popcount(msk)>q) continue;
	    for(int i=0;i<m;i++){
		if(bit(msk,i)){
		    if(ch[q]=='p'){
			if(b[q]==1) dp[q&1][msk]=max(dp[q&1][msk],dp[!(q&1)][msk ^ (1<<i)]+a[i]);
			if(b[q]==2) dp[q&1][msk]=min(dp[q&1][msk],dp[!(q&1)][msk ^ (1<<i)]-a[i]);
		    }
		    else{
			if(b[q]==1) dp[q&1][msk]=max(dp[q&1][msk],max(dp[!(q&1)][msk],dp[!(q&1)][msk ^ (1<<i)]));
			if(b[q]==2) dp[q&1][msk]=min(dp[q&1][msk],min(dp[!(q&1)][msk],dp[!(q&1)][msk ^ (1<<i)]));
		    }
		}
	    }
	}
    }
    cout<<dp[0][(1<<m)-1]<<endl;
    return 0;
}