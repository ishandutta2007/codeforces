#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &n);
	vector<vector<int>> a(3, vector<int>(n));
	for(i=0; i<3; i++) {
		string s;
		cin >> s;
		for(j=0; j<n; j++) {
			a[i][j] = s[j]-'0';
		}
	}
	vector<vector<int>> v(3, vector<int>(n, 0));
	vector<vector<int>> d{{-1,0},{1,0},{0,-1},{0,1}};
	vector<int> ladd(n, 0), radd(n, 0);
	for(i=0; i<3; i++) {
		for(j=0; j<n; j++) {
			int l = n, r = 0;
			if(a[i][j] && !v[i][j]) {
				queue<vector<int>> to;
				to.push({i, j});
				v[i][j] = 1;
				while(!to.empty()) {
					vector<int> node = to.front();
					to.pop();
					int x = node[0], y = node[1];
					l = min(l, y);
					r = max(r, y);
					for(k=0; k<4; k++) {
						int nx = x+d[k][0], ny = y+d[k][1];
						if(0<=nx&&nx<3&&0<=ny&&ny<n && a[nx][ny] && !v[nx][ny]) {
							to.push({nx, ny});
							v[nx][ny] = 1;
						}
					}
				}
				ladd[l]++;
				radd[r]++;
			}
		}
	}
	vector<int> lsum(n+1, 0), rsum(n+1, 0);
	for(i=0; i<n; i++) {
		lsum[n-1-i] = lsum[n-i]+ladd[n-1-i];
		rsum[i+1] = rsum[i]+radd[i];
	}
	vector<int> lp(n, -1), rp(n, -1);
	for(i=0; i<n; i++) {
		if(a[0][i] && a[1][i] && a[2][i]) {
			for(j=i-1; j>=0 && a[0][j] && !a[1][j] && a[2][j]; j--) {
				rp[j] = i;
			}
			for(j=i+1; j<n && a[0][j] && !a[1][j] && a[2][j]; j++) {
				lp[j] = i;
			}
		}
	}
	/*for(i=0; i<n; i++) {
		printf("%d ", ladd[i]);
	}
	printf("\n");
	for(i=0; i<n; i++) {
		printf("%d ", radd[i]);
	}
	printf("\n");
	for(i=0; i<=n; i++) {
		printf("%d ", lsum[i]);
	}
	printf("\n");
	for(i=0; i<=n; i++) {
		printf("%d ", rsum[i]);
	}
	printf("\n");*/
	scanf("%d", &q);
	for(i=0; i<q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		int answer = 0;
		answer += rsum[n];
		answer -= rsum[l];
		answer -= lsum[r];
		if(lp[l] != -1 && rp[l] != -1 && rp[l] >= r) {
			answer++;
		} else {
			if(lp[l] != -1 && rp[l] == -1) {
				answer++;
			}
			if(rp[r-1] != -1 && lp[r-1] == -1) {
				answer++;
			}
		}
		printf("%d\n", answer);
	}
}