#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define PB push_back
#define ST first
#define ND second

set<int> *v;
bool *vis;
queue<int> kolejka;

int dfs(int a) {
	int res=1;
	vis[a] = true;
	vector<int> nf, f;
	while(!kolejka.empty()) {
		int b = kolejka.front();
		kolejka.pop();
		auto it = v[a].find(b);
		if(it != v[a].end()) {
			nf.PB(b);
		}
		else {
			f.PB(b);
		}
	}
	for(int i=0; i < nf.size(); i++)
		kolejka.push(nf[i]);
	for(int i=0; i < f.size(); i++) {
		if(vis[f[i]] == false) {
			vis[f[i]] = true;
			res+=dfs(f[i]);
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	v = new set<int> [n+1];
	vis = new bool[n+1];
	for(int i=0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].insert(b);
		v[b].insert(a);
	}
	for(int i=1; i <= n; i++)
	{
		vis[i] = false;
		kolejka.push(i);
	}
	kolejka.pop();
	vector<int> res;
	for(int i=1; i<=n; i++)
	{
		if(vis[i] == false)
		{
			res.PB(dfs(i));
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for(int i=0; i < res.size(); i++) {
		cout << res[i] << " ";
	}


	return 0;
}