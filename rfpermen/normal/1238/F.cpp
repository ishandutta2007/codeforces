#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int q,n,a,b,ans;
vector<int> tmp[MAX],v[MAX];
vector<pii> sub[MAX];
 
inline bool cmp(pii aa,pii bb){
	return aa.fi>bb.fi;
}
 
void dfs(int nw,int par){
	for(auto i:tmp[nw]){
		if(i==par)continue;
		v[nw].pb(i);
		dfs(i,nw);
		sub[nw].pb({sub[i][0].fi+(nw==1 ? tmp[nw].size() : tmp[nw].size()-1 ),i});
	}
	sub[nw].pb({v[nw].size(),0});
	sort(all(sub[nw]),cmp);
	return;
}
 
void f(int nw,int at){
//	cout<<nw<<" = "<<at<<endl;
	if(sub[nw].size()==1){ans = max(ans,at+1); return;}
	
//	cout<<nw<<" = "<<sub[nw][0].fi<<"  ___  "<<max(sub[nw][1].fi - (int)v[nw].size(),at) + 1<<endl;
//	cout<< sub[nw][0].fi + max(sub[nw][1].fi - (int)v[nw].size() + 2,at+1) << endl;
	
	ans = max(ans,sub[nw][0].fi + max(sub[nw][1].fi - (int)v[nw].size() + (nw!=1),at) + 1);
//	cout<<nw<<' '<<ans<<endl;
	
	if(v[nw].size()==1){f(v[nw][0],at+1); return;}
	
	for(auto i:v[nw]){
		if(i==sub[nw][0].se)f(i, max(at+(int)v[nw].size(), sub[nw][1].fi+(nw!=1)));
		else f(i, max(at+(int)v[nw].size(), sub[nw][0].fi+(nw!=1)));
	}
	
	return;
}
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q;
    while(q--){
    	cin>>n;
    	rep(i,1,n)tmp[i].clear(), v[i].clear(), sub[i].clear();
    	rep(i,2,n){
    		cin>>a>>b;
    		tmp[a].pb(b);
    		tmp[b].pb(a);
		}
		dfs(1,0);
//		cout<<"\n\n";
//		for(auto i:sub[2])cout<<i.fi<<' '<<i.se<<endl;
//		db(sub[4][1].fi);
		ans = 0;
		f(1,0);
		cout<<ans<<endl;
	}
    return 0;
}