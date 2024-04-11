#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define w fi
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdi pair<double,int>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,k,p,q,dp[(1<<16)];
bool x[16][16];
string a,b,s[16];
map<string,int> m;
vector<string> ans;
int f(int idx,int mask){
	if(idx>n)return dp[mask] = 0;
	rep(i,0,idx-1){
		if(mask&(1<<i) && x[idx][i])return dp[mask] = f(idx+1,mask);
	}
	return dp[mask] = max(f(idx+1,mask),f(idx+1,mask|(1<<idx))+1);
}

void bt(int idx,int mask){
	if(idx>n)return;
	if(dp[mask]==dp[mask|(1<<idx)]+1){
		ans.pb(s[idx]);
		bt(idx+1,mask|(1<<idx));
		return;
	}
	bt(idx+1,mask);
}

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k; n--;
    rep(i,0,n){
    	cin>>s[i];
    	m[s[i]] = i;
	}
	while(k--){
		cin>>a>>b;
		p = m[a];
		q = m[b];
		x[p][q] = 1;
		x[q][p] = 1;
	}
	p=(1<<n)-1;
	rep(i,0,p)dp[i]=-2;
	cout<<f(0,0)<<endl;
	bt(0,0);
	sort(ans.begin(),ans.end());
	for(auto i:ans)cout<<i<<endl;
    return 0;
}