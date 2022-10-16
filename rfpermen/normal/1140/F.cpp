#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1e12;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,a,b,l,r,x,y,num,p[MAX<<1];
ll cx[MAX<<1],cy[MAX<<1],ans;
map<pii,int> hs;
pii z[MAX];
vector<int> v[MAX];
vector<pii> tree[1<<20];
 
int par(int z){
	if(p[z]==z)return z;
	return par(p[z]);
}
 
void upd(int id,int le,int ri){
	if(le>r||ri<l)return;
	if(le>=l&&ri<=r){
		tree[id].pb({x,y});
		return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	return;
}
 
void que(int id,int le,int ri){
	vector<piiii> rb;
	for(auto i:tree[id]){
		a = par(i.fi), b = par(i.se);
		if(a!=b){
			if(cx[a]+cy[a]>cx[b]+cy[b])swap(a,b);
			rb.pb({{a,p[a]},{cx[a],cy[a]}});
			rb.pb({{b,p[b]},{cx[b],cy[b]}});
			p[a] = b;
			ans-= cx[a]*cy[a] + cx[b]*cy[b];
			cx[b]+= cx[a], cy[b]+= cy[a], cx[a] = cy[a] = 0;
			ans+= cx[b]*cy[b];
		}
	}
	if(le!=ri){
		int mid = le+ri>>1;
		que(lc,le,mid), que(rc,mid+1,ri);
	}
	else cout<<ans<<' ';
	reverse(all(rb));
	for(auto i:rb){
		ans-= cx[i.ff]*cy[i.ff] - i.sf*i.ss;
		p[i.ff] = i.fs;
		cx[i.ff] = i.sf;
		cy[i.ff] = i.ss;
	}
	rb.clear();
	return;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x>>y; y+= 300000;
    	if(!hs.count({x,y}))hs[{x,y}] = hs.size(), z[hs.size()] = {x,y};
    	v[hs[{x,y}]].pb(i);
	}
	rep(i,1,n){
		l = -1;
		x = z[i].fi, y = z[i].se;
		for(int j:v[i]){
			if(l==-1)l = j;
			else {
				r = j-1;
				upd(1,1,n);
				l = -1;
			}
		}
		if(l!=-1)r = n, upd(1,1,n);
	}
	rep(i,1,300000)p[i] = i, cx[i] = 1;
	rep(i,300001,600000)p[i] = i, cy[i] = 1;
	
	que(1,1,n);
	cout<<endl;
	return 0;
}