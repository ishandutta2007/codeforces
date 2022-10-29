#include<bits/stdc++.h>
#define int ll

typedef long long ll;
using namespace std;

struct nod{
	int tot, am, ou;
};

struct seg{
	int n;
	vector<nod> st;
	vector<int> A, lazy;
	seg(int sz) : n(sz), st(4*n), lazy(4*n,0) {}
	seg(vector<int> ini) : seg((int)ini.size()) {
		A = ini;
		build(0,n-1,1);
	}

	nod mer(nod a, nod b){
		nod c;
		c.tot = a.tot+b.tot;
		c.am = a.am+b.am;
		c.ou = a.ou+b.ou;
		return c;
	}

	void build(int l, int r, int p){
		if(l == r){
			nod c;
			c.tot = A[l];
			c.am = 0;
			c.ou = 0;
			st[p] = c;
			return;
		}
		int m = (l+r)>>1;
		build(l,m,p<<1);
		build(m+1,r,p<<1|1);
		st[p] = mer(st[p<<1],st[p<<1|1]);
	}

	void prop(int p){
		if((p<<1|1) < (int)lazy.size()){
			lazy[p<<1] ^= lazy[p];
			lazy[p<<1|1] ^= lazy[p];
		}
		lazy[p] = 0;
	}

	void upd(int l, int r, int i, int j, int p){
		if(lazy[p]){
			st[p].am = (j-i+1)-st[p].am;
			st[p].ou = st[p].tot-st[p].ou;
			prop(p);
		}
		if(l > j || r < i)return;
		if(i >= l && j <= r){
			lazy[p]++;
			st[p].am = (j-i+1)-st[p].am;
			st[p].ou = st[p].tot-st[p].ou;
			prop(p);
			return;
		}
		int m = (i+j)>>1;
		upd(l,r,i,m,p<<1);
		upd(l,r,m+1,j,p<<1|1);
		st[p] = mer(st[p<<1],st[p<<1|1]);
	}
};

vector<int> sz, p, nxt, in, v2;
vector<vector<array<int,2>>> g;
int cnt = 0;

void dfs(int x){
	if(g[x][0][0] == p[x])swap(g[x][0],g[x].back());
	for(auto &y : g[x]){
		if(y[0] == p[x])continue;
		p[y[0]] = x;
		dfs(y[0]);
		sz[x]+=sz[y[0]];
		if(sz[y[0]] > sz[g[x][0][0]])swap(y,g[x][0]);
	}
}
void dfs2(int x, int val){
	in[x] = cnt++;
	v2.push_back(val);
	for(auto y : g[x]){
		if(y[0] == p[x])continue;
		nxt[y[0]] = (y == g[x][0] ? nxt[x] : y[0]);
		dfs2(y[0],y[1]);
	}
}

signed main(){
	int n; cin >> n;
	g.resize(n);
	sz.resize(n,1);
	in.resize(n);
	nxt.resize(n);
	nxt[0] = 0;
	p.resize(n);
	p[0] = -1;
	for(int i = 0; i < n-1; ++i){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].push_back({b,i+1});
		g[b].push_back({a,i+1});
	}
	dfs(0);
	dfs2(0,0);
	/*
	for(int i = 0; i < n; ++i){
		cout << "i -> " << i << "\tsz: " << sz[i] << "\tp: " << p[i] << "\tnxt: " << nxt[i] << "\tin: " << in[i] << "\tv2: " << v2[i] << endl;
	}
	*/
	seg ST(v2);
	ST.upd(0,0,0,n-1,1);
	int cn = 1;
	vector<pair<int,int>> edg;
	int num = 0;
	int x;
	while(cin >> x){
		if(x == 1){
			cn++;
			int a; cin >> a;
			a--;
			edg.emplace_back(p[a],a);
			while(a != -1){
				ST.upd(in[nxt[a]],in[a],0,n-1,1);
				a = p[nxt[a]];
			}
			if(ST.st[1].am*2 == cn){
				cout << ST.st[1].ou << '\n';
				num++;
			}
			else{
				cout << "0\n";
				num++;
			}
		}
		if(x == 2){
			if(ST.st[1].am*2 != cn){
				cout << "0\n";
				num++;
				continue;
			}
			cout << cn/2 << ' ';
			num++;
			vector<int> con(n,0);
			for(auto y : edg){
				con[y.first]++, con[y.second]++;
			}
			queue<int> lef;
			for(int i = 1; i < n; ++i){
				if(con[i] == 1)lef.push(i);
			}
			vector<int> dum;
			while(lef.size()){
				auto y = lef.front();
				lef.pop();
				dum.push_back(v2[in[y]]);
				if(p[p[y]] != -1 && p[p[y]] != 0){
					con[p[p[y]]]--;
					if(con[p[p[y]]] == 1)lef.push(p[p[y]]);
				}
			}
			sort(dum.begin(),dum.end());
			for(auto y : dum){cout << y << ' ';num++;}
			cout << '\n';
		}
		if(x == 3)break;
	}
}