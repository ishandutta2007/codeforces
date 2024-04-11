#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,sz[MAX],pos,k,x[MAX],tmp,ans,hit,Z;
vector<int> v[MAX],z[3];

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], --x[i];
    rep(i,1,n){
    	cin>>k;
    	while(k--){
    		cin>>pos;
    		v[pos].pb(i);
		}
	}
	ans = 1e9;
	pos = 0, tmp = n;
	rep(i,1,n)for(auto j:v[i])++sz[j];
	rep(i,1,n)if(!sz[i])z[x[i]].pb(i);
	hit = n;
	while(1){
		while(!z[pos].empty()){
			Z = z[pos].back();
			z[pos].pob();
			--hit;
			for(auto i:v[Z]){
				--sz[i];
				if(!sz[i])z[x[i]].pb(i);
			}
		}
		if(!hit)break;
		pos = (pos+1)%3, ++tmp;
	}
	ans = min(ans,tmp);
	pos = 1, tmp = n;
	rep(i,1,n)for(auto j:v[i])++sz[j];
	rep(i,1,n)if(!sz[i])z[x[i]].pb(i);
	hit = n;
	while(1){
		while(!z[pos].empty()){
			Z = z[pos].back();
			z[pos].pob();
			--hit;
			for(auto i:v[Z]){
				--sz[i];
				if(!sz[i])z[x[i]].pb(i);
			}
		}
		if(!hit)break;
		pos = (pos+1)%3, ++tmp;
	}
	ans = min(ans,tmp);
	pos = 2, tmp = n;
	rep(i,1,n)for(auto j:v[i])++sz[j];
	rep(i,1,n)if(!sz[i])z[x[i]].pb(i);
	hit = n;
	while(1){
		while(!z[pos].empty()){
			Z = z[pos].back();
			z[pos].pob();
			--hit;
			for(auto i:v[Z]){
				--sz[i];
				if(!sz[i])z[x[i]].pb(i);
			}
		}
		if(!hit)break;
		pos = (pos+1)%3, ++tmp;
	}
	ans = min(ans,tmp);
	cout<<ans<<endl;
	return 0;
}