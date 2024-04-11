#include<bits/stdc++.h>

using namespace std;

vector<int> ufa, mar, ind, pos;
vector<vector<int>> gr;
int cn = 0;
string ans;

int uf(int x) { return ufa[x] = ufa[x] ^ x ? uf(ufa[x]) : x;}

void ini(int x, int p){
	ind[x] = cn++;
	for(auto y : gr[x])if(y != p)ini(y,x);
	pos[x] = cn++;
}

void dfs(int x, int p, int su){
	su+=mar[x];
	if(cn == su)ans[x] = '1';
	for(auto y : gr[x]){
		if(y == p)continue;
		dfs(y,x,su);
	}
}

void solve(){
	int n, m; cin >> n >> m;
	ufa.resize(n);
	mar.resize(n,0);
	ans.resize(n,'0');
	ind.resize(n,0);
	pos.resize(n,0);
	gr.resize(n);
	iota(ufa.begin(),ufa.end(),0);
	vector<pair<int,int>> Q;
	for(int i = 0; i < m; ++i){
		int a, b; cin >> a >> b, a--, b--;
		int ua = uf(a), ub = uf(b);
		if(ua != ub){
			gr[a].push_back(b);
			gr[b].push_back(a);
			ufa[ua] = ub;
		}
		else{
			Q.emplace_back(a,b);
		}
	}
	ini(0,0);
	int cu = 0;
	for(auto x : Q){
		if(ind[x.first] > ind[x.second])swap(x.first,x.second);
		if(pos[x.first] > pos[x.second]){
			cu++;
			mar[x.second]++;
			int l = 0, r = (int)gr[x.first].size()-1, bes = 0;
			while(l <= r){
				int m = (l+r)>>1;
				if(pos[gr[x.first][m]] >= pos[x.first] && ind[gr[x.first][m]] <= ind[x.first]){m++;}
				if(pos[gr[x.first][m]] >= pos[x.second] && ind[gr[x.first][m]] <= ind[x.second]){bes = m; break;}
				if(pos[gr[x.first][m]] < pos[x.second])l = m+1;
				else r = m-1;
			}
			mar[gr[x.first][bes]]--;
		}
		else{
			mar[x.first]++;
			mar[x.second]++;
		}
	}
	cn = m-n+1;
	dfs(0,0,cu);
	cout << ans << '\n';
}

int main(){
	solve();

}