#include<bits/stdc++.h>
#define ll long long
#define rep(i,n,N) for(int i = n; i<=N; ++i)
#define asd(i,n,N) for(int i = n; i< N; ++i)
#define rap(i,n,N) for(int i = n; i>=N; --i)
#define pb push_back
#define mems(a,b) memset(a,b,sizeof a)
#define all(x) x.begin(),x.end()
#define db(x) cout << ">>> " << #x << " = " << x << endl
#define lc (id<<1)
#define rc ((id<<1)|1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second

using namespace std;

const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 1000000009;
const ll key = 36671;

int n,x[MAX],nw,dp[MAX];
map<int,vector<int> > hs;
bool vis[MAX];
vector<int> ans;

int main(){
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>x[i];
		hs[x[i]].pb(i);
	}
	rap(i,n,1){
		nw = i;
		if(hs.count(x[nw]+1)){
			auto it = lower_bound(all(hs[x[nw]+1]),nw);
			if(it!=hs[x[nw]+1].end())dp[i] = dp[*it];
		}
		++dp[i];
	}
	nw = 0;
	rep(i,1,n)if(dp[i]>dp[nw])nw = i;
	ans.pb(nw);
	while(hs.count(x[nw]+1)){
		auto it = lower_bound(all(hs[x[nw]+1]),nw);
		if(it==hs[x[nw]+1].end())break;
		nw = *it;
		ans.pb(nw);
	}
	cout<<ans.size()<<endl;
	for(int i:ans)cout<<i<<' '; cout<<endl;
	return 0;
}