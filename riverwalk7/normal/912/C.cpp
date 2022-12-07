#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define pii pair<int,int>
using namespace std;
int n, m, AA, inc, K, INF = 2e9;
struct point {
	int M, R;
	vector<pii>T;
}w[101000];
map<int, int>B;
int main() {
	int i, h, t, a, j;
	scanf("%d%d%d%d%d", &n,&m,&AA,&inc,&K);
	for (i = 1; i <= n; i++) {
		scanf("%d%d%d", &w[i].M, &h, &w[i].R);
		w[i].T.push_back({ 0, h });
	}
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &t, &a, &h);
		w[a].T.push_back({ t,h });
	}
	int ck = 0;
	for (i = 1; i <= n; i++) {
		sort(w[i].T.begin(), w[i].T.end());
		if (w[i].M <= K && inc) {
			ck = 1;
		}
		if (w[i].T.back().second <= K && w[i].R == 0 && inc) {
			ck = 1;
		}
		w[i].T.push_back({ INF,0 });
		for (j = 0; j < w[i].T.size() - 1; j++) {
			pii tp = w[i].T[j];
			int t1 = tp.first, hh = tp.second;
			int t2 = w[i].T[j + 1].first;
			if (hh > K)continue;
			if (w[i].R == 0 || w[i].M <= K) {
				B[t1]++;
				B[t2]--;
			}
			else {
				int tt = (K - hh) / w[i].R;
				B[t1]++;
				B[min(t2, t1 + tt + 1)]--;
			}
		}
	}
	if (ck) {
		printf("-1\n");
		return 0;
	}
	int s = 0;
	long long r = 0;
	for (auto &tp : B){
		long long t = 1ll*s*AA + 1ll*s*inc*(tp.first - 1);
		r = max(r, t);
		s += tp.second;
	}
	printf("%lld\n", r);
}