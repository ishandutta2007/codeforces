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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=5e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,z[MAX],hs[MAX],k,a,b,c,q,dp[MAX],pr;
vector<int> v[MAX];
bool lz[3*MAX],x[3*MAX],vis[MAX],ck;

void dfs(int i){
	++k;
	vis[i] = 1;
	hs[i] = k;
	for(auto j:v[i]){
		if(vis[j])continue;
		dp[j] = i;
		dfs(j);
	}
	z[hs[i]] = k;
	return;
}
inline void f(int &id,int &le,int &ri){
	x[id] = 1;
	if(le!=ri){
		lz[id*2]=1;
		lz[id*2+1]=1;
	}
	lz[id]=0;
	return;
}
void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){f(id,le,ri); return;}
	int mid = (le+ri)/2;
	upd(id*2,le,mid);
	upd(id*2+1,mid+1,ri);
	x[id] = x[id*2]&x[id*2+1];
	return;
}
void up(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le==ri){x[id]=0; return;}
	int mid = (le+ri)/2;
	if(a<=mid)up(id*2,le,mid);
	else up(id*2+1,mid+1,ri);
	x[id] = x[id*2]&x[id*2+1];
	return;
}
bool que(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return 1;
	if(le>=a&&ri<=b)return x[id];
	int mid = (le+ri)/2;
	return que(id*2,le,mid)&que(id*2+1,mid+1,ri);
}

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	dfs(1);
//	rep(i,1,n)cout<<i<<" "; cout<<endl;
//	rep(i,1,n)cout<<hs[i]<<" "; cout<<endl;
	cin>>q;
	while(q--){
		cin>>c>>a;
		pr = dp[a];
		a = hs[a];
		b = z[a];
		if(c==1){
			ck = que(1,1,n);
			upd(1,1,n);
			if(!ck&&a!=1)a = hs[pr], up(1,1,n);
		}
		else if(c==2)up(1,1,n);
		else cout<<que(1,1,n)<<endl;
	}
    return 0;
}