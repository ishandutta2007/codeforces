#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,m,q,x[MAX],y[MAX],z[MAX],sp[18][MAX],bt,a,b,nx;
vector<int> v[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    rep(i,1,n)cin>>x[i], z[x[i]] = i;
    rep(i,1,m)cin>>y[i], v[y[i]].pb(i);
    rep(i,1,m){
    	nx = x[z[y[i]]%n+1];
    	auto it = lower_bound(all(v[nx]),i);
    	if(it==v[nx].end())continue;
    	sp[0][i] = v[nx][it-v[nx].begin()];
	}
	bt = log2(n);
	rep(j,1,bt)rep(i,1,m)sp[j][i] = sp[j-1][sp[j-1][i]];
	int cnt,tmp;
	rep(i,1,m){
		cnt = 0, tmp = n-1, nx = i;
		while(tmp){
			if(tmp&1)nx = sp[cnt][nx];
			tmp>>=1, cnt++;
		}
		if(!nx)z[i] = m+1;
		else z[i] = nx;
	}
	rap(i,m-1,1)z[i] = min(z[i],z[i+1]);
	while(q--){
		cin>>a>>b;
		if(z[a]>b)cout<<0;
		else cout<<1;
	}
	cout<<endl;
	return 0;
}