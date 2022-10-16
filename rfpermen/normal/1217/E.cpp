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
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000004381;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,x[MAX],y[MAX][9],q,mul,lg,pos,ty,a,b,ans;
pii tree[1<<19][9],res;

void build(int id,int le,int ri){
	if(le==ri){
		tree[id][pos] = {y[le][pos],lg};
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	pii &t1 = tree[lc][pos], &t2 = tree[rc][pos];
	if(t1.fi<=t2.fi){
		tree[id][pos].fi = t1.fi;
		if(t1.se<=t2.fi)tree[id][pos].se = t1.se;
		else tree[id][pos].se = t2.fi;
	}
	else {
		tree[id][pos].fi = t2.fi;
		if(t2.se<=t1.fi)tree[id][pos].se = t2.se;
		else tree[id][pos].se = t1.fi;
	}
	return;
}

pii que(int id,int le,int ri){
	if(le>b||ri<a)return {lg,lg};
	if(le>=a&&ri<=b)return tree[id][pos];
	int mid = le+ri>>1;
	pii t1 = que(lc,le,mid), t2 = que(rc,mid+1,ri), ret;
	if(t1.fi<=t2.fi){
		ret.fi = t1.fi;
		if(t1.se<=t2.fi)ret.se = t1.se;
		else ret.se = t2.fi;
	}
	else {
		ret.fi = t2.fi;
		if(t2.se<=t1.fi)ret.se = t2.se;
		else ret.se = t1.fi;
	}
	return ret;
}

void upd(int id,int le,int ri){
	if(le==ri){
		tree[id][pos] = {y[le][pos],lg};
		return;
	}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	pii &t1 = tree[lc][pos], &t2 = tree[rc][pos];
	if(t1.fi<=t2.fi){
		tree[id][pos].fi = t1.fi;
		if(t1.se<=t2.fi)tree[id][pos].se = t1.se;
		else tree[id][pos].se = t2.fi;
	}
	else {
		tree[id][pos].fi = t2.fi;
		if(t2.se<=t1.fi)tree[id][pos].se = t2.se;
		else tree[id][pos].se = t1.fi;
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("gift.in", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    lg = 1000000000;
    cin>>n>>q;
    rep(i,1,n){
    	cin>>x[i];
    	mul = 1;
    	rep(j,0,8){
    		if(x[i]/mul%10)y[i][j] = x[i];
    		else y[i][j] = lg;
    		mul*=10;
		}
	}
	rep(i,0,8)pos = i, build(1,1,n);
	while(q--){
		cin>>ty>>a>>b;
		if(ty&1){
			x[a] = b;
    		mul = 1;
	    	rep(i,0,8){
	    		if(x[a]/mul%10)y[a][i] = x[a];
	    		else y[a][i] = lg;
	    		pos = i, upd(1,1,n);
	    		mul*=10;
			}
		}
		else {
			ans = 2000000000;
	    	rep(i,0,8){
	    		pos = i;
				res = que(1,1,n);
				if(res.se!=lg)ans = min(ans,res.fi+res.se);
			}
			if(ans!=2000000000)cout<<ans<<endl;
			else cout<<"-1\n";
		}
	}
	return 0;
}