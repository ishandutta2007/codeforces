#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1500 + 10;
int n, m, a[N][N], b[N][N], nex[N][N], p[N];
pair<int,vector<int> > A[N], B[N];
bool cmp(pair<int,vector<int> > A, pair<int,vector<int> > B) {
	if (B.second == A.second) 
		return A.first < B.first;
	return A.second < B.second;
}
int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i ++) {
		vector<int> tmp(m, 0);
		for (int j = 1; j <= m; j ++) {
			scanf("%d", &a[i][j]); tmp[j - 1] = a[i][j]; 
		}
		A[i] = make_pair(i, tmp);

	}	

	for (int i = 1; i <= n; i ++) {
		vector<int> tmp(m, 0);
		for (int j = 1; j <= m; j ++) {
			scanf("%d", &b[i][j]); tmp[j - 1] = b[i][j];
		}
		B[i] = make_pair(i, tmp);
	}	

	bool flush = 1;
	for (int i = 1; i <= n; i ++) if (A[i].second != B[i].second) flush = 0;
	if (flush) {
		return !printf("0\n");
	}
	for (int i = n; i >= 1; i --) {
		for (int j = 1; j <= m; j ++) {
			if (i < n && b[i][j] <= b[i+1][j]) 
				nex[i][j] = nex[i+1][j];
			else
				nex[i][j] = i + 1;
		}
	} 
	 
	sort(A + 1, A + 1 + n, cmp);
	sort(B + 1, B + 1 + n, cmp);

	for (int i = 1; i <= n; i ++) {
		if (A[i].second != B[i].second) return !printf("-1\n");
		p[B[i].first] = A[i].first;
	}

	vector<int> fouls(m + 1, 0);
	queue<int> q;
	for (int i = 1; i <= m; i ++) {
		if (nex[1][i] == n+1) {
			q.push(i);
		} else {
			fouls[i] = 1;
		}
	}

	vector<int> v; v.push_back(1); v.push_back(n+1);
	vector<int> ans;
	while (q.size()) {
		int c = q.front(); q.pop();
		// printf("c = %d\n", c);
		vector<int> add; 
		ans.push_back(c);
		for (int i = 0; i + 1 < v.size(); i ++) {
			int pre = v[i];
			for (int l = v[i], r = v[i]; r < v[i+1]; l = r) {
				while (r < v[i+1] && b[r][c] == b[l][c]) r ++;
				if (r != v[i+1]) {
					add.push_back(r);
					for (int j = 1; j <= m; j ++) if (fouls[j]) {
						if (nex[pre][j] < v[i+1]) {
							fouls[j] --;
							if (nex[pre][j] < r) fouls[j] ++;
							if (nex[r][j] < v[i+1]) fouls[j] ++;
							if (fouls[j] == 0) q.push(j);
						}
					}
					pre = r;
				}
			}
		}
		for (auto x: add) v.push_back(x);
		sort(v.begin(), v.end());
	}
	bool ook = true;
	if (ans.size() == 0) return !printf("-1\n");
	for (int i = 1; i < n; i ++) {
		int x = p[i], y = p[i+1];
		bool ok = true;
		for (int j = 0; j < ans.size(); j ++) {
			int col = ans[j];
			if (a[x][col] < a[y][col]) break;
			if (a[x][col] > a[y][col]) {
				ok = false; break;
			}
			if (j == ans.size() - 1)
				ok = x < y;
		}
		ook &= ok;
	}	
	if (!ook) return !printf("-1\n");
	reverse(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (auto x: ans) printf("%d ", x);
}