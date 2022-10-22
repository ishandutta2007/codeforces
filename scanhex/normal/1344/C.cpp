#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=200200;
vector<int> g[N];
vector<int> gr[N];

int col[N];
void d(int u) {
	if (col[u] == 1) {
		 cout << -1 << '\n';
		 exit(0);
	}
	if (col[u] == 2)
		return;
	col[u]=1;
	for(int v : g[u])
		d(v);
	col[u]=2;
}

bool used[N];
vector<int>ord;
void ts(int u) {
	if (used[u])return;
	used[u]=true;
	for(int v : g[u])
		ts(v);
	ord.push_back(u);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;++i){
		int a,b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		gr[b].push_back(a);
	}
	for(int i=0;i<n;++i) {
		sort(g[i].begin(),g[i].end());
		sort(gr[i].begin(),gr[i].end());
	}
	for(int i=0;i<n;++i){
		if (col[i] == 0)
			d(i);
	}
	for(int i = 0; i < n; ++i) 
		ts(i);
	reverse(ord.begin(),ord.end());
	vector<int>mn1(n, n), mn2(n, n);
	for(int i=0;i<n;++i) { 
		int x = ord[i];
		mn2[x] = x;
		for(int y : gr[x])
			mn2[x] = min(mn2[x], mn2[y]);
	}
	for(int i=n-1; i >= 0; --i) {
		int x = ord[i];
		mn1[x] = x;
		for(int y : g[x])
			mn1[x] = min(mn1[x], mn1[y]);
	}
	string ans;
	int c=0;
	for(int i=0;i<n;++i) {
		bool e = mn1[i] < i || mn2[i] < i;
		if (e)
			ans.push_back('E');
		else
			ans.push_back('A'),++c;
	}
	cout << c << '\n';
	cout << ans << '\n';

	return 0;
}