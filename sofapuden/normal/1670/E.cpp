#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int cn = 1;
int n;
vector<int> val1, val2;
vector<vector<pair<int,int>>> tr;

void dfs(int x, int p, int pat){
	if(x){
		val1[x] = cn^(val1[p]&n)^n;
		val2[pat] = val1[x]^n;
		cn++;
	}	
	for(auto y : tr[x]){
		if(y.first != p)dfs(y.first,x,y.second);
	}
}

void solve(int testID){
	int p; cin >> p;
	n = 1<<p;
	val1.clear();
	val2.clear();
	val1.resize(n,0);
	val2.resize(n-1,0);
	val1[0] = n;
	cn = 1;
	tr.clear();
	tr.resize(n);
	for(int i = 0; i < n-1; ++i){
		int a, b; cin >> a >> b;
		a--, b--;
		tr[a].emplace_back(b,i);
		tr[b].emplace_back(a,i);
	}
	dfs(0,0,0);
	cout << 1 << '\n';
	for(auto x : val1)cout << x << ' ';
	cout << '\n';
	for(auto x : val2)cout << x << ' ';
	cout << '\n';

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	int cnt = 1;
	while(t--){
		solve(cnt++);

	}

}