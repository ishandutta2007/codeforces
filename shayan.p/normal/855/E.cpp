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

const int MLG=65,MB=10,MMSK=(1<<10)+10;

ll dp[MLG][MB][MMSK];
vector<int>vec;

ll solve(ll x,int b){
    vec.clear();
    ll ans=0;
    while(x>0){
	vec.PB(x%b);
	x/=b;
    }
    for(int i=2;i<sz(vec);i++){
	ans+=dp[i][b-1][0]-dp[i-1][b-1][1];
    }
    int msk=0;
    for(int i=sz(vec)-1;i>=0;i--){
	for(int j=(i==(sz(vec)-1));j<vec[i];j++){
	    ans+=dp[i][b-1][msk^(1<<j)];
	}
	msk^=(1<<vec[i]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=0;i<MB;i++)
	dp[0][i][0]=1;
    for(int i=1;i<MLG;i++){
	for(int j=0;j<MB;j++){
	    for(int k=0;k<MMSK;k++){
		for(int w=0;w<=j;w++){
		    dp[i][j][k]+=dp[i-1][j][k^(1<<w)];
		}
	    }
	}
    }
    int q;cin>>q;
    while(q--){
	int b;ll l,r;cin>>b>>l>>r;
	cout<<solve(r+1,b)-solve(l,b)<<"\n";
    }
    return 0;
}