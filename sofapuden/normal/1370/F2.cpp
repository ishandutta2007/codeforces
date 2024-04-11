#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<int,int> query(vector<int> v){
	cout << "? " << v.size() << ' ';
	for(auto x : v)cout << x << ' ';
	cout << endl;
	pair<int,int> qu;
	cin >> qu.first >> qu.second;
	return qu;
}

void dfs(int x, int p, vector<vector<int>> &ord, vector<vector<int>> &tr, int d = 0){
	ord[d].push_back(x+1);
	for(auto y : tr[x]){
		if(y != p)dfs(y,x,ord,tr,d+1);
	}
}

void solve(){
	int n; cin >> n;
	vector<vector<int>> tr(n);
	for(int i = 0; i < n-1; ++i){
		int a, b; cin >> a >> b, a--, b--;
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	vector<int> qu(n);
	iota(qu.begin(),qu.end(),1);

	//1st query
	pair<int,int> no = query(qu);

	int dis = no.second, root = no.first;

	vector<vector<int>> ord(n+5);
	dfs(root-1, root-1, ord, tr);

	while(ord.back().empty())ord.pop_back();

	int l = (dis+1)/2, r = min((int)ord.size()-1,dis);

	int fi = root;

	// 2nd to log2(r-l)+2 query
	while(l <= r){
		int m = (l+r)>>1;
		no = query(ord[m]);
		if(no.second == dis){
			fi = no.first;
			l = m+1;
		}
		else{
			r = m-1;
		}
	}

	ord.clear();
	ord.resize(n+5);
	dfs(fi-1,fi-1,ord,tr);
	
	//last query
	no = query(ord[dis]);
	cout << "! " << fi << ' ' << no.first << endl;
	string s; cin >> s;
	assert(s == "Correct");
}

int main(){
	int t; cin >> t;
	while(t--)solve();
}