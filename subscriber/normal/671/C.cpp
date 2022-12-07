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
#define N 211111

#define TASK "1"

using namespace std;

int n;
vector<int> d[N];
int a[N];
int s[N];
int was[N];

int ap[N], f[N];
int did[N];

void add(int x, int v) {
	while (x < n) {
		s[x] = max(s[x], v);
		x  |= x + 1;
	}
}

int get(int x) {
	int r = 0;
	while (x >= 0) {
		r = max(r, s[x]);
		x = (x & (x + 1)) - 1;
	}
	return r;
}

long long sum = 0;

void up(int x, int val) {
	if (get(x) >= val) return;
	while (get(x) < val) {
		int v = get(x);

		int l = x;
		int r = n - 1;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (get(mid) == v) l = mid; else r = mid - 1;
		}
		int to = val;
		if (l < n - 1) to = min(to, get(l + 1));

		sum += (to - v) * (l - x + 1);		
		add(x, to);
	}			
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	for (int i = 1; i <= 200000; i++) {
		int j = i;
		while (j <= 200000) {
			d[j].pb(i);
			j += i;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d[a[i]].size(); j++) {
			if (was[d[a[i]][j]]) ap[i] = max(ap[i], d[a[i]][j]);
			was[d[a[i]][j]] = 1;
		}			
		ap[i + 1] = ap[i];
	}
	for (int i = 0; i < n; i++) add(i, ap[i]);
	for (int i = 0; i < n; i++) sum += ap[i];
	
	for (int i = 1; i <= 200000; i++) f[i] = n, was[i] = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < d[a[i]].size(); j++) f[d[a[i]][j]] = min(f[d[a[i]][j]], i);

	int my = 0;
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) ans += ap[i];

	for (int i = n - 1; i >= 1; i--) {
		int h = a[i];
		for (int j = 0; j < d[h].size(); j++) {
			if (was[d[h][j]]) my = max(my, d[h][j]);
			was[d[h][j]] = 1;

			int ps = f[d[h][j]];
			if (!did[d[h][j]]) {
				did[d[h][j]] = 1;
				up(ps, d[h][j]);
			}
		}
		ans += my;

		up(0, my);
		up(i - 1, 1000000);

		int bad = n - i + 1;

		ans += sum - bad * 1000000ll;
	}
	cout << ans << endl;

	return 0;
}