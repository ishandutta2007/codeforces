#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,m,k,a,b,c,x;
ll dp[MAX][205];
pii y[MAX],lz[3*MAX];

inline void g(int &id,int &le,int &ri){
	if(le==ri)y[le] = max(y[le],lz[id]);
	else {
		lz[lc] = max(lz[lc],lz[id]);
		lz[rc] = max(lz[rc],lz[id]);
	}
	lz[id] = lz[0];
	return;
}

void upd(int id,int le,int ri){
	if(lz[id].fi)g(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){lz[id] = {c,x+1}; g(id,le,ri); return;}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	return;
}
void rex(int id,int le,int ri){
	if(lz[id].fi)g(id,le,ri);
	if(le==ri)return;
	int mid = le+ri>>1;
	rex(lc,le,mid), rex(rc,mid+1,ri);
	return;
}
ll f(int nw,int rem){
	if(nw>n)return 0;
	if(dp[nw][rem]!=-1)return dp[nw][rem];
	if(rem)return dp[nw][rem] = min(f(y[nw].se,rem)+y[nw].fi,f(nw+1,rem-1));
	return dp[nw][rem] = f(y[nw].se,rem)+y[nw].fi;
}

int main(){
//	cout<<fixed<<setprecision(1);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)y[i].se = i+1;
    rep(i,1,k){
    	cin>>a>>b>>x>>c;
    	upd(1,1,n);
	}
	rex(1,1,n);
	memset(dp,-1,sizeof dp);
	cout<<f(1,m)<<endl;
    return 0;
}