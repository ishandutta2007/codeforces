#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	long long ml = 1e18;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d %d", &n, &m, &k);
		int x[n];
		for(i=0; i<n; i++) {
			scanf("%d", &x[i]);
		}
		vector<int> p[k];
		vector<vector<int>> s[n];
		for(i=0; i<k; i++) {
			for(j=0; j<5; j++) {
				scanf("%d", &in);
				if(j < 4) {
					in--;
				} else {
					in = -in;
				}
				p[i].push_back(in);
			}
			s[p[i][0]].push_back({p[i][1], i, 0});
			s[p[i][2]].push_back({p[i][3], i, 1});
		}
		for(i=0; i<n; i++) {
			sort(s[i].begin(), s[i].end());
		}
		long long dist[k];
		for(i=0; i<k; i++) {
			dist[i] = ml;
		}
		for(i=0; i<s[0].size(); i++) {
			int pos = s[0][i][0];
			int idx = s[0][i][1];
			dist[idx] = (long long)x[0]*pos;
		}
		/*for(i=0; i<k; i++) {
			printf("%lld ", dist[i]);
		}
		printf("\n");*/
		for(i=1; i<n; i++) {
			long long cur = ml;
			for(j=0; j<s[i].size(); j++) {
				int pos = s[i][j][0];
				int idx = s[i][j][1];
				if(s[i][j][2] == 0) {
					dist[idx] = min(dist[idx], cur+(long long)x[i]*pos);
				} else if(dist[idx] != ml) {
					cur = min(cur, dist[idx]+p[idx][4]-(long long)x[i]*pos);
				}
			}
			cur = ml;
			for(j=(int)s[i].size()-1; j>=0; j--) {
				int pos = s[i][j][0];
				int idx = s[i][j][1];
				if(s[i][j][2] == 0) {
					dist[idx] = min(dist[idx], cur+(long long)x[i]*(m-pos));
				} else if(dist[idx] != ml) {
					cur = min(cur, dist[idx]+p[idx][4]-(long long)x[i]*(m-pos));
				}
			}
		/*for(j=0; j<k; j++) {
			printf("%lld ", dist[j]);
		}
		printf("\n");*/
		}
		long long answer = ml;
		for(i=0; i<s[n-1].size(); i++) {
			int pos = s[n-1][i][0];
			int idx = s[n-1][i][1];
			if(dist[idx] != ml) {
				answer = min(answer, dist[idx]+p[idx][4]+(long long)x[n-1]*(m-1-pos));
			}
		}
		if(answer == ml) {
			printf("NO ESCAPE\n");
		} else {
			printf("%lld\n", answer);
		}
	}
}