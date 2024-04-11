#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d %d", &n, &k);
	k--;
	int a[n], b[n];
	for(i=0; i<n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	int x;
	
	auto on_line = [&](vector<int> p) {
		return ((long long)a[p[1]]-a[p[0]])*(b[p[2]]-b[p[0]]) == ((long long)a[p[2]]-a[p[0]])*(b[p[1]]-b[p[0]]);
	};
	
	if(n == 3) {
		x = 0;
	} else {
		if(on_line({0, 1, 2})) {
			for(i=3; i<n; i++) {
				if(!on_line({0, 1, i})) {
					x = i;
					break;
				}
			}
		} else {
			for(i=0; i<3; i++) {
				vector<int> e;
				for(j=0; j<=3; j++) {
					if(j != i) {
						e.push_back(j);
					}
				}
				if(on_line(e)) {
					x = i;
					break;
				}
			}
		}
	}
	
	vector<vector<int>> p;
	for(i=0; i<n; i++) {
		if(i != x) {
			p.push_back({a[i], b[i]});
		}
	}
	sort(p.begin(), p.end());
	p.push_back({a[x], b[x]});
	for(i=0; i<n; i++) {
		if(a[k] == p[i][0] && b[k] == p[i][1]) {
			k = i;
			break;
		}
	}
	
	auto distance = [&](vector<int> path) {
		double total = 0;
		int i;
		for(i=0; i<path.size()-1; i++) {
			total += sqrt(pow(p[path[i]][0]-p[path[i+1]][0], 2)+pow(p[path[i]][1]-p[path[i+1]][1], 2));
		}
		return total;
	};
	
	double answer = distance({k, n-1, 0, n-2});
	answer = min(answer, distance({k, n-1, n-2, 0}));
	answer = min(answer, distance({k, 0, n-2, n-1}));
	answer = min(answer, distance({k, n-2, 0, n-1}));
	if(k != n-1) {
	    answer = min(answer, distance({k, 0, n-1, n-2, k+1}));
	    answer = min(answer, distance({k, 0, n-1, k+1, n-2}));
	}
	if(k != 0) {
	    answer = min(answer, distance({k, n-2, n-1, 0, k-1}));
	    answer = min(answer, distance({k, n-2, n-1, k-1, 0}));
	}
	if(distance({0, k}) < distance({n-2, k})) {
		for(i=0; i<n-2; i++) {
	        answer = min(answer, distance({k, 0, i, n-1, i+1, n-2}));
		}
	} else {
		for(i=0; i<n-2; i++) {
	        answer = min(answer, distance({k, n-2, i+1, n-1, i, 0}));
		}
	}
	printf("%f", answer);
}