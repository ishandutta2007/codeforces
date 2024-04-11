#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>

using namespace std;

typedef long long ll;
typedef pair < ll, int > pli;

#define maxn 100001
#define maxp 101

#define mp make_pair

int dist[maxn], t[maxn];
int f[maxn];
int n, m, p;
ll ans[maxn][maxp];
ll sum[maxn];
pli stack[maxn];
int beg, en;

const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
	ll res = 0LL;
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> p;
	dist[1] = 0;
	for (int i = 2; i <= n; ++i) {
		cin >> dist[i];
		dist[i] += dist[i - 1];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> f[i] >> t[i];
		f[i] = -dist[f[i]] + t[i];
		res -= f[i];
	}
	sort(f + 1, f + m + 1);
	sum[0] = 0LL;
	for (int pos = 0; pos <= m; ++pos)
		ans[pos][1] = ll(pos) * f[pos];
	for (int cnt = 2; cnt <= p; ++cnt) {
		ans[0][cnt] = 0LL;
		beg = 1, en = 0;
		for (int pos = 1; pos <= m; ++pos) {
			ll curG = ans[pos - 1][cnt - 1];
			while (beg < en) {
				pli lst = stack[en], llst = stack[en - 1];
				if ((pos - 1 - lst.second) * (llst.first - lst.first) - 
					(curG - lst.first) * (llst.second - lst.second) <= 0LL)
					--en;
				else
					break;
			}
			stack[++en] = mp(curG, pos - 1);
			pli best;
			while (beg < en) {
				pli one = stack[beg], two = stack[beg + 1];
				if (one.first - (ll) f[pos] * one.second > two.first - (ll) f[pos] * two.second)
					++beg;
				else
					break;
			}
			best = stack[beg];
			ans[pos][cnt] = min(ans[pos][cnt - 1], best.first + ll(pos - best.second) * f[pos]);
		}
	}
	cout << ans[m][p] + res << endl;
	return 0;
}