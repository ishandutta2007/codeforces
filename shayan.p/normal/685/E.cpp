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

const int maxn=1010,Max=2e5+10,inf=1e9;

int A[Max],B[Max],dp[maxn][maxn];
bool ans[Max];
pair<pair<pii,pii>,int> p[Max];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,q;cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
	cin>>A[i]>>B[i];
    }
    for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
	    dp[i][j]=dp[j][i]=inf;
	}
    }
    for(int i=1;i<=q;i++){
	cin>>p[i].F.F.F>>p[i].F.F.S>>p[i].F.S.F>>p[i].F.S.S;
	p[i].S=i;
    }
    int nw=m;
    sort(p+1,p+q+1);
    for(int i=q;i>=1;i--){
	while(p[i].F.F.F<=nw){
	    dp[A[nw]][B[nw]]=dp[B[nw]][A[nw]]=nw;
	    for(int j=1;j<=n;j++){
		if(j==A[nw] || j==B[nw]) continue;
		dp[A[nw]][j]=dp[B[nw]][j]=min(dp[A[nw]][j],dp[B[nw]][j]);
	    }
	    --nw;
	}
	ans[p[i].S]=(dp[p[i].F.S.F][p[i].F.S.S]<=p[i].F.F.S);
    }
    for(int i=1;i<=q;i++){
	cout<<(ans[i]?"Yes\n":"No\n");
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.