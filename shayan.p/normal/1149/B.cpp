// Faster!

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

const int maxn=260,maxn2=1e5+10,mod=1e9+7;
const ll inf=1e18;

int len[3],lst[maxn2][30],dp[maxn][maxn][maxn];
int chr[3][maxn],n;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>n>>q;
    string s;cin>>s;
    for(int j=n;j<maxn2;j++){
	for(int i=0;i<26;i++){
	    lst[j][i]=n+1;
	}
    }
    for(int i=n-1;i>=0;i--){
	for(int j=0;j<26;j++){
	    lst[i][j]=lst[i+1][j];
	}
	lst[i][s[i]-'a']=i;
    }
    while(q--){
	char task;cin>>task;
	int who;
	char ch;
	if(task=='+'){
	    cin>>who>>ch;
	    --who,++len[who];
	    chr[who][len[who]]=ch-'a';

	    for(int i= ( who==0 ? len[0] : 0 ); i<= len[0]; i++){
		for(int j= ( who==1 ? len[1] : 0 ); j<= len[1]; j++){
		    for(int k= ( who==2 ? len[2] : 0 ); k<= len[2]; k++){
			dp[i][j][k]=n+2;
			if(i>0) dp[i][j][k]= min(dp[i][j][k], lst[ dp[i-1][j][k] ][ chr[0][i] ]+1);
			if(j>0) dp[i][j][k]= min(dp[i][j][k], lst[ dp[i][j-1][k] ][ chr[1][j] ]+1);
			if(k>0) dp[i][j][k]= min(dp[i][j][k], lst[ dp[i][j][k-1] ][ chr[2][k] ]+1);
		    }
		}
	    }
	}
	else{
	    cin>>who; --who;
	    --len[who];
	}
	cout<<(dp[len[0]][len[1]][len[2]]<=n ? "YES\n" : "NO\n");
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.