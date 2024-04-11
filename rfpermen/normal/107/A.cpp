#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<int,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,ans,a,b,c,cnt;
bool en[MAX];
vector<pii> v[MAX];

void dfs(int i){
	b = i;
	for(auto j:v[i]){
		ans = min(ans,j.se);
		dfs(j.fi);
	}
	return;
}

int main(){
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--){
    	cin>>a>>b>>c;
    	v[a].pb({b,c});
    	en[b] = 1;
	}
	rep(i,1,n)if(!v[i].empty()&&!en[i])cnt++;
	cout<<cnt<<endl;
	rep(i,1,n){
		if(!v[i].empty()&&!en[i]){
			cout<<i;
			ans = v[i][0].se;
			dfs(i);
			cout<<" "<<b<<" "<<ans<<endl;
		}
	}
    return 0;
}