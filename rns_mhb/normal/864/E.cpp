#include <bits/stdc++.h>
using namespace std;
#define N 110
#define M 2010
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, dp[N][M];

struct item{
	int t, d, p, id;
	bool operator < (item x) const {return d < x.d;}
}a[N];
vector<int> v;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].p);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		for (int x = 0; x < M; x ++) {
			dp[i][x] = dp[i-1][x];
			if (x < a[i].d && a[i].t <= x) chkmax(dp[i][x], dp[i-1][x-a[i].t] + a[i].p);
		}
	}
	int x = max_element(dp[n], dp[n] + M) - dp[n];
	cout<<dp[n][x]<<endl;
	for (int i = n; i >= 1; i --) {
		if (dp[i][x] > dp[i-1][x]) {
			x -= a[i].t;
			v.pb(a[i].id);
		}
	}
	cout<<v.size()<<endl;
	for (int i = v.size() - 1; i >= 0; i --) printf("%d ", v[i]);
    return 0;
}