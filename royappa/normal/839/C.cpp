#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	unordered_map<int,unordered_set<int>> adj;
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].insert(b);
		adj[b].insert(a);
	}
	unordered_map<int,int> dist;
	unordered_map<int,double> prob;
	dist[1] = 0;
	prob[1] = 1.0;

	queue<int> q;
	q.push(1);
	double tot = 0.0;
	while (q.size() > 0) {
		int h = q.front();
		q.pop();
		int nbrs = adj[h].size();
		//cout << h << " : " << nbrs << " / " << dist[h] << " / " << prob[h] << endl;
		if (h == 1 || nbrs > 1) {
			for (auto v : adj[h]) {
				if (dist.count(v) == 0) {
					q.push(v);
					dist[v] = dist[h]+1;
					if (h == 1) {
						prob[v] = prob[h]*(1.0/nbrs);
					}
					else {
						prob[v] = prob[h]*(1.0/(nbrs-1));
					}
				}
			}
		}
		else {
			tot += dist[h]*prob[h];
		}
	}
	printf("%.12lf\n", tot);
	exit(0);
}