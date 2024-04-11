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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>>" << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

int n,id,tree[3*MAX],a,res, y[MAX],val;
pii x[MAX];
vector<int> v[MAX];
inline bool cmp(pii &a,pii &b){
	if(a.fi==b.fi)return a.se>b.se;
	return a.fi<b.fi;
}
void upd(int id,int le,int ri){
	if(le==ri){tree[id] = val; return;}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = min(tree[lc],tree[rc]);
}
int que(int id,int le,int ri){
	if(le>a)return MOD;
	if(ri<=a)return tree[id];
	int mid = le+ri>>1;
	return min(que(lc,le,mid),que(rc,mid+1,ri));
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,600000)tree[i] = MOD;
    cin>>n;
    rep(i,1,n)cin>>x[i].fi, x[i].se = i;
    sort(x+1,x+1+n,cmp);
    rep(i,1,n)y[i] = x[i].fi, x[i].fi = i, x[i].fi^=x[i].se^=x[i].fi^=x[i].se;
	sort(x+1,x+1+n);
	rep(i,1,n){
		a = x[i].se-1;
		res = que(1,1,n);
		if(res==MOD){
			v[++id].pb(x[i].se);
			a = v[id].back(), val = id;
			upd(1,1,n); 
		}
		else {
			a = v[res].back(), val = MOD;
			upd(1,1,n);
			v[res].pb(x[i].se);
			a = v[res].back(), val = res;
			upd(1,1,n); 
		}
	}
	rep(i,1,id){
		for(auto j:v[i])cout<<y[j]<<' ';
		cout<<endl;
	}
    return 0;
}