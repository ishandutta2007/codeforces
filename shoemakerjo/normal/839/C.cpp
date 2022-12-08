#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adjt;

double ex(int par, int num) {
	int si = adjt[num].size()-1;
	if (par == 0) si++;
	double ep = 0.0;
	for (int i = 0; i < adjt[num].size(); i++) {
		int v = adjt[num][i];
		if (v == par) continue;
	
		ep += (1.0/(si+0.0))*(ex(num,v)+1.0);
		// cout << num << " " << v << " " << ep << endl;
	}
	return ep;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n+1; i++) {
		vector<int> b;
		adjt.push_back(b);
	
	}
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adjt[u].push_back(v);
		adjt[v].push_back(u);
	}
	cout << fixed << setprecision(15);
	cout << ex(0, 1) << endl;
	// cin >> n;
}