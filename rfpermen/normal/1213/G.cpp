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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,q,id,p[MAX],a,b;
ll ans,res[MAX],sz[MAX];
piii e[MAX];
pii que[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    if(n==1){
    	while(q--)cout<<"0 ";
    	return 0;
	}
	rep(i,1,n)p[i] = i, sz[i] = 1;
	rep(i,2,n)cin>>e[i].sf>>e[i].ss>>e[i].fi;
	rep(i,1,q)cin>>que[i].fi, que[i].se = i;
	sort(e+2,e+1+n);
	sort(que+1,que+1+q);
	id = 2;
	rep(i,1,q){
		while(id<=n&&e[id].fi<=que[i].fi){
			a = par(e[id].sf), b = par(e[id].ss);
			ans+=sz[a]*sz[b];
			sz[a]+=sz[b];
			p[b] = a;
			sz[b] = 0;
			++id;
		}
		res[que[i].se] = ans;
	}
	rep(i,1,q)cout<<res[i]<<' ';
	return 0;
}