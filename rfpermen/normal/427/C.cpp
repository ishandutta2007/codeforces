#include <bits/stdc++.h>
#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
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
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,a,b,x[MAX],cur,mf[MAX],num[MAX],cnt,id,mn;
ll res,ans;
bool vis[MAX];
vector<int> v[MAX],scc[MAX];
stack<int> s;

//void dfs(int nw){
//	s.push(nw);
//	vis[nw] = 1;
//	num[nw] = mf[nw] = ++cnt;
//	for(auto i:v[nw]){
//		if(!num[i]){
//			dfs(i);
//		}
//		if(vis[i])mf[nw] = min(mf[nw],mf[i]);
//	}
//	if(num[nw]==mf[nw]){
//		id++;
//		while(!s.empty()){
//			cur = s.top(); s.pop();
//			vis[cur] = 0;
////			mf[cur] = mf[nw];
//			scc[id].pb(cur);
//			if(cur==nw)break;
//		}
//	}
//}

void dfs(int nw){
	s.push(nw);
	vis[nw] = 1;
	num[nw] = mf[nw] = ++cnt;
	for(auto i:v[nw]){
		if(!num[i])dfs(i);
		if(vis[i])mf[nw] = min(mf[nw],mf[i]);
	}
	if(num[nw]==mf[nw]){
		id++;
		while(!s.empty()){
			cur = s.top(); s.pop();
			vis[cur] = 0;
			scc[id].pb(cur);
			if(cur==nw)break;
		}
	}
}

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    cin>>m;
    while(m--){
    	cin>>a>>b;
    	v[a].pb(b);
	}
	rep(i,1,n){
		if(num[i])continue;
		dfs(i);
	}
	//cout<<"----------\n";
	//rep(i,1,n)cout<<num[i]<<" "<<mf[i]<<endl;
	//cout<<"-----------\n";
	//cout<<id<<endl;
	//cout<<"Jumlah stack = "<<s.size()<<endl;
	res = 1;
	rep(i,1,id){
		mn = 1e9+1;
		cnt= 0;
		for(auto j:scc[i])mn = min(x[j],mn);
		ans+=mn;
		for(auto j:scc[i])if(mn==x[j])cnt++;
		//for(auto j:scc[i])cout<<i<<" -> "<<j<<endl;
		//cout<<mn<<endl;
		res = (res*cnt)%MOD;
	}
	cout<<ans<<" "<<res<<endl;
    return 0;
}