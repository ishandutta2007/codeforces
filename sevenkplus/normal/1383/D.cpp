#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 253
int n, m;
int a[N][N];
int b[N][N];
int p[N*N];
int px[N], py[N];
int vx[N], vy[N];

const int dx[4] = {1, 0, -1 ,0};
const int dy[4] = {0, 1, 0, -1};

bool valid(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m) return false;
	if (b[i][j]) return false;
	int k = 0;
	if (i+1 < n && j-1 >= 0 && b[i+1][j] > k && b[i][j-1] > k) return true;
	if (i-1 >= 0 && j+1 < m && b[i-1][j] > k && b[i][j+1] > k) return true;
	return false;
}

int main() {
	// srand(time(NULL));
	// n = m = 20;
	// vector<int> aa;
	// for (int i = 0; i < n; i ++)
	// 	for (int j = 0; j < m; j ++) aa.pb(i*m+j);
	// random_shuffle(aa.begin(), aa.end());
	// for (int i = 0; i < n; i++)
	// 	for (int j = 0; j < m; j ++)
	// 		a[i][j] = aa[i*m+j]+1;
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) {
			cin >> a[i][j];
			px[i] = max(px[i], a[i][j]);
			py[j] = max(py[j], a[i][j]);
		}
	for (int i = 0; i < n; i ++) p[px[i]] ^= 1;
	for (int j = 0; j < m; j ++) p[py[j]] ^= 2;
	sort(px, px+n);
	reverse(px, px+n);
	sort(py, py+m);
	reverse(py, py+m);
	
	for (int i = 0; i < n; i ++) {
		// printf("R %d %d\n", i, px[i]);
		for (int j = 0; j < m; j ++)
			if (py[j] >= px[i]) vx[i]++;
		vx[i]--;
		b[i][vx[i]] = px[i];
	}

	for (int j = 0; j < m; j ++) {
		// printf("C %d %d\n", j, py[j]);
		for (int i = 0; i < n; i ++)
			if (px[i] >= py[j]) vy[j]++;
		vy[j]--;
		b[vy[j]][j] = py[j];
	}

	set<PII> A;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) if (valid(i, j)) A.insert(mp(i, j));

	for (int k = n*m; k >= 1; k--) if (!p[k]) {
		bool F = false;
		for (auto p : A) {
			int i = p.fi;
			int j = p.se;
			if (i+1 < n && j-1 >= 0 && b[i+1][j] > k && b[i][j-1] > k
			|| i-1 >= 0 && j+1 < m && b[i-1][j] > k && b[i][j+1] > k) {
				b[i][j] = k;
				F = true;
				A.erase(mp(i, j));
				for (int d = 0; d < 4; d ++) {
					if (valid(i+dx[d],j+dy[d])) A.insert(mp(i+dx[d], j+dy[d]));
				}
				break;
			}
		}
		assert(F);
	}
	

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			printf("%d%c", b[i][j], j == m-1?'\n':' ');
	return 0;
}