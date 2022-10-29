#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;

ll mx = (1ll<<50);

struct Line{
	ll a, b;
	Line(ll _a, ll _b) : a(_a), b(_b) {}
	ll eval(ll x){
		return a*x + b;
	}
};

struct LCT{
	LCT *lt, *rt;
	Line val;

	int l, r;
	LCT(int _l, int _r) : l(_l), r(_r), lt(nullptr), rt(nullptr), val(Line(0,mx)) {}

	void ex(){
		int m = (l+r)>>1;
		if(lt == nullptr){
			lt = new LCT(l,m-1);
		}
		if(rt == nullptr){
			rt = new LCT(m+1,r);
		}
	}

	void ins(Line f){
		if(l > r)return;
		int m = (l+r)>>1;
		bool me = f.eval(m) < val.eval(m);
		bool le = f.eval(l) < val.eval(l);
		if(me){
			swap(f,val);
		}
		ex();
		if(me == le){
			rt->ins(f);
		}else{
			lt->ins(f);
		}
	}
	ll que(ll x){
		int m = (l+r)>>1;
		if(m < x){
			if(rt == nullptr)return val.eval(x);
			return min(val.eval(x),rt->que(x));
		}
		else{
			if(lt == nullptr)return val.eval(x);
			return min(val.eval(x),lt->que(x));
		}
	}
};

vector<int> A, B;
vector<vector<int>> tr;
vector<ll> ans;
vector<LCT*> nodes;
vector<vector<pair<ll,ll>>> lst;

void f(int x, int p){
	bool lf = 1;
	for(auto y : tr[x]){
		if(y == p)continue;
		lf = 0;
		f(y,x);
		if(lst[x].size() < lst[y].size()){
			swap(lst[x],lst[y]);
			swap(nodes[x],nodes[y]);
		}
		for(auto y : lst[y]){
			lst[x].push_back(y);
			nodes[x]->ins(Line(y.first,y.second));
		}
	}
	if(!lf)ans[x] = nodes[x]->que(A[x]);
	else ans[x] = 0;
	nodes[x]->ins(Line(B[x],ans[x]));
	lst[x].push_back({B[x],ans[x]});
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	A.resize(n);
	B.resize(n);
	tr.resize(n);
	lst.resize(n);
	ans.resize(n);
	nodes.resize(n);
	for(auto &x : nodes)x = new LCT(-1e5-5,1e5+5);
	for(auto &x : A)cin >> x;
	for(auto &x : B)cin >> x;
	for(int i = 0; i < n-1; ++i){
		int u, v; cin >> u >> v;
		u--, v--;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	f(0,0);
	for(auto x : ans)cout << x << ' ';
	cout << '\n';
}