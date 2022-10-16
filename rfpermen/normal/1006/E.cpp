#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define w fi
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdi pair<double,int>
#define endl "\n"
const ll MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,k,p,q,x[MAX],y[MAX],z[MAX],idx;
vector<int> v[MAX];

int dfs(int pos){
	int tmp = 1;
	x[++idx] = pos;
	y[pos] = idx;
	for(auto i:v[pos]){
		tmp += dfs(i);
	}
	return z[pos] = tmp;
}

int main(){
	//cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,2,n)cin>>p, v[p].pb(i);
    dfs(1);
    while(q--){
    	cin>>p>>k;
    	if(z[p]<k)cout<<"-1\n";
    	else cout<<x[y[p]+k-1]<<endl;
	}
    return 0;
}