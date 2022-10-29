#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

class ST{
public:
	ST(int sz) : n(sz), st(4*n), lazy1(4*n,-1), lazy2(4*n,0) {}
	ST(const vector<ll> &ini) : ST((int)ini.size()) {
		A = ini;
		build(1,0,n-1);
	}
	void upd1(int i, int j, ll val){upd1(1,0,n-1,i,j,val);}
	void upd2(int i, int j, ll val){upd2(1,0,n-1,i,j,val);}
	ll que(int i, int j){return que(1,0,n-1,i,j);}
 
private:
	int n;
	vector<ll> st, lazy1, lazy2, A;
 
	int l(int p){return p<<1;}
	int r(int p){return (p<<1)+1;}
 
	ll merge(ll a, ll b){
		return min(a,b);
	}
 
	void build(int p, int L, int R){
		if(L == R){
			st[p] = A[L];
		}
		else{
			int m = (L+R)>>1;
			build(l(p),L,m);
			build(r(p),m+1,R);
			st[p] = merge(st[l(p)],st[r(p)]);
		}
	}
 
	void prop(int p, int L, int R){
		if(lazy1[p] != -1){
			st[p] = lazy1[p];
			if(L != R){
				lazy1[l(p)] = lazy1[r(p)] = lazy1[p];
				lazy2[l(p)] = lazy2[r(p)] = 0;
			}
			lazy1[p] = -1;
		}
		if(lazy2[p]){
			st[p] += lazy2[p];
			if(L != R){
				lazy2[l(p)]+=lazy2[p];
				lazy2[r(p)]+=lazy2[p];
			}
			lazy2[p] = 0;
		}
	}
 
	void upd1(int p, int L, int R, int i, int j, ll val){
		prop(p,L,R);
		if(i > j)return;
		if(L >= i && R <= j){
			lazy1[p] = val;
			lazy2[p] = 0;
			prop(p,L,R);
		}
		else{
			int m = (L+R)>>1;
			upd1(l(p),L,m,i,min(j,m),val);
			upd1(r(p),m+1,R,max(i,m+1),j,val);
			st[p] = merge(st[l(p)],st[r(p)]);
		}
	}
 
	void upd2(int p, int L, int R, int i, int j, ll val){
		prop(p,L,R);
		if(i > j)return;
		if(L >= i && R <= j){
			lazy2[p] += val;
			prop(p,L,R);
		}
		else{
			int m = (L+R)>>1;
			upd2(l(p),L,m,i,min(j,m),val);
			upd2(r(p),m+1,R,max(i,m+1),j,val);
			st[p] = merge(st[l(p)],st[r(p)]);
		}
	}
	
	ll que(int p, int L, int R, int i, int j){
		prop(p,L,R);
		if(i > j)return (1ll<<60);
		if(L >= i && R <= j)return st[p];
		int m = (L+R)>>1;
		return merge(que(l(p),L,m,i,min(j,m)),que(r(p),m+1,R,max(i,m+1),j));
	}
};

vector<vector<pair<ll,ll>>> gr;
vector<vector<array<ll,3>>> Q;
vector<pair<ll,ll>> interval;
vector<ll> ans;
int n;

pair<int,int> ini(int x){
	pair<int,int> ret = {x,x};
	for(auto y : gr[x]){
		pair<int,int> n = ini(y.first);
		ret.first = min(n.first,ret.first);
		ret.second = max(n.second,ret.second);
	}
	return interval[x] = ret;
}

ST st(1);

void dfs(int x){
	int s = gr[x].size();
	if(s == 0){
		st.upd1(x,x,0);
	}
	for(int i = 0; i < s; ++i){
		auto y = gr[x][i];
		st.upd2(0,n-1,y.second);
		dfs(y.first);
		st.upd2(0,n-1,-y.second);
		st.upd2(interval[y.first].first,interval[y.first].second,y.second<<1);
	}
	for(auto y : Q[x]){
		ans[y[2]] = min(ans[y[2]], st.que(y[0],y[1]));
	}
}

void rdfs(int x){
	int s = gr[x].size();
	if(s == 0)st.upd1(x,x,0);
	for(int i = s-1; ~i; --i){
		auto y = gr[x][i];
		st.upd2(0,n-1,y.second);
		rdfs(y.first);
		st.upd2(0,n-1,-y.second);
		st.upd2(interval[y.first].first,interval[y.first].second,y.second<<1);
	}
	for(auto y : Q[x]){
		ans[y[2]] = min(ans[y[2]], st.que(y[0],y[1]));
	}
}

void solve(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q;
	gr.resize(n);
	interval.resize(n);
	ans.resize(q,(1ll<<49));
	Q.resize(n);
	for(int i = 1; i < n; ++i){
		ll x, y; cin >> x >> y;
		x--;
		gr[x].emplace_back(i,y);
	}
	for(int i = 0; i < q; ++i){
		ll a, b, c; cin >> a >> b >> c;
		a--, b--, c--;
		Q[a].push_back({b,c,i});
	}
	ini(0);
	st = ST(vector<ll>(n,(1ll<<49)));
	dfs(0);
	st = ST(vector<ll>(n,(1ll<<49)));
	rdfs(0);
	for(auto x : ans)cout << x << '\n';
}

int main(){
	solve();
}