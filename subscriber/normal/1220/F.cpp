#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 911111

#define TASK "1"

using namespace std;

int a[N];
int lg[N];
int f[20][N];
int n;

int solve(int l, int r) {
	if (l > r) return 0;
	if (l == r) return 1;

	int w = lg[r - l + 1];
	int x = f[w][l];
	int y = f[w][r - pw(w) + 1];
	if (a[y] < a[x]) x = y;
	return max(solve(l, x - 1), solve(x + 1, r)) + 1;
}

int solveL(int s, int h) {
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (solve(s - mid, s - 1) > h) r = mid - 1; else l = mid;
	}
	//cout << "solveL " << h << " " << l << endl;
	return l;
}

int solveR(int s, int h) {
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (solve(s + 1, s + mid) > h) r = mid - 1; else l = mid;
	}
	//cout << "solveR " << h << " " << l << endl;
	return l;
}


int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) a[i + n] = a[i], a[i + n + n] = a[i];

	int m = n * 3;
	for (int i = 0; i < m; i++) f[0][i] = i;
	for (int i = 1; pw(i) <= m; i++) for (int j = 0; j + pw(i) <= m; j++) {
		int x = f[i - 1][j];
		int y = f[i - 1][j + pw(i - 1)];
		if (a[x] < a[y]) f[i][j] = x; else f[i][j] = y;
	}
	lg[1] = 0;
	for (int i = 2; i <= m; i++) lg[i] = lg[i / 2] + 1;

	int s = -1;
	for (int i = 0; i < n; i++) if (a[i] == 1) s = i;

	int ans;

	int l = 0;
	int r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		int len1 = solveL(s + n, mid);
		int len2 = solveR(s + n, mid);
		if (len1 + 1 + len2 < n) l = mid + 1; else {
			r = mid;
			ans = len1;
		}
	}
	cout << l + 1 << " " << ((s - ans + n) % n) << endl;

	return 0;
}