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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,m,x[MAX],ty,a,b,md;
pll tree[1<<18];

ll que(int id,int le,int ri){
	if(le>b||ri<a)return 0;
	if(le>=a&&ri<=b)return tree[id].fi;
	int mid = le+ri>>1;
	return que(lc,le,mid) + que(rc,mid+1,ri);
}
void upd(int id,int le,int ri){
	if(le==ri){tree[id] = {b,b}; return;}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = {tree[lc].fi+tree[rc].fi,max(tree[lc].se,tree[rc].se)};
	return;
}
void upde(int id,int le,int ri){
	if(tree[id].se<md)return;
	if(le>b||ri<a)return;
	if(le==ri){tree[id] = {tree[id].fi%md,tree[id].se%md}; return;}
	int mid = le+ri>>1;
	upde(lc,le,mid), upde(rc,mid+1,ri);
	tree[id] = {tree[lc].fi+tree[rc].fi,max(tree[lc].se,tree[rc].se)};
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>x[i], a = i, b = x[i], upd(1,1,n);
    while(m--){
    	cin>>ty>>a>>b;
    	if(ty==1)cout<<que(1,1,n)<<endl;
    	else if(ty==2)cin>>md, upde(1,1,n);
		else upd(1,1,n);
	}
	return 0;
}