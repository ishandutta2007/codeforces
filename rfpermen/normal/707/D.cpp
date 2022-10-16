#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,m,q,cnt[MAX],ty[MAX*100],ans[MAX*100],res;
pii z[MAX*100];
bool st[MAX],x[MAX][MAX];
vector<int> v[MAX*100];

void dfs(int nw){
	bool mv = ty[nw]!=4 ? st[z[nw].fi] : 0;
	bool rb = 0;
	if(ty[nw]==1){
		if(x[z[nw].fi][z[nw].se]==mv){
			rb = 1;
			++res, ++cnt[z[nw].fi];
			x[z[nw].fi][z[nw].se]^= 1;
		}
	}
	else if(ty[nw]==2){
		if(x[z[nw].fi][z[nw].se]!=mv){
			rb = 1;
			--res, --cnt[z[nw].fi];
			x[z[nw].fi][z[nw].se]^= 1;
		}
	}
	else if(ty[nw]==3){
		rb = 1;
		res+= m-cnt[z[nw].fi]*2;
		cnt[z[nw].fi] = m-cnt[z[nw].fi];
		st[z[nw].fi]^=1;
	}
	ans[nw] = res;
	for(int i:v[nw])dfs(i);
	if(rb){
		if(ty[nw]==1){
			--res, --cnt[z[nw].fi];
			x[z[nw].fi][z[nw].se]^= 1;
		}
		else if(ty[nw]==2){
			++res, ++cnt[z[nw].fi];
			x[z[nw].fi][z[nw].se]^= 1;
		}
		else {
			res+= m-cnt[z[nw].fi]*2;
			cnt[z[nw].fi] = m-cnt[z[nw].fi];
			st[z[nw].fi]^=1;
		}
	}
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
	rep(i,1,q){
		cin>>ty[i];
		if(ty[i]<3)cin>>z[i].fi>>z[i].se;
		else cin>>z[i].fi;
		if(ty[i]==4)v[z[i].fi].pb(i);
		else v[i-1].pb(i);
	}
	for(int i:v[0])dfs(i);
	rep(i,1,q)cout<<ans[i]<<endl;
    return 0;
}