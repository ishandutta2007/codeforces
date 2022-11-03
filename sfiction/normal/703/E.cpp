#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, ll> PIL;

const int MAXN = 1E3 + 10, MAXT = 1E4;

int n;
ll K, a[MAXN];
vector<PIL> d;
vector<int> dn;

int pre[MAXN][MAXT];
PIL f[MAXN][MAXT];

int main(){
	scanf("%d%I64d", &n, &K);
	for (int i = 1; i <= n; ++i)
		scanf("%I64d", &a[i]);
	if (K == 1){
		printf("1\n%d\n", min_element(a + 1, a + n + 1) - a);
		return 0;
	}

	int tot = 1;
	dn.push_back(1);
	for (ll i = 2; i * i <= K; ++i)
		if (K % i == 0){
			int t = 0;
			for (; K % i == 0; ++t, K /= i);
			d.push_back(PIL(t, i));
			dn.push_back(tot *= t + 1);
		}
	if (K > 1){
		d.push_back(PIL(1, K));
		dn.push_back(tot <<= 1);
	}


	fill_n(f[0] + 1, tot - 1, PIL(1 << 30, 1ll << 60));
	vector<int> b(d.size());
	for (int i = 1; i <= n; ++i){
		ll t = a[i];
		for (int j = 0; j < d.size(); ++j)
			for (b[j] = 0; t % d[j].nd == 0; ++b[j], t /= d[j].nd);

		for (int j = tot - 1; j >= 0; --j){
			f[i][j] = f[i - 1][j];
			pre[i][j] = j;

			int v2 = 0;
			for (int v1 = j, k = 0; k < d.size(); ++k){
				v2 += min(d[k].st, v1 % (d[k].st + 1) + b[k]) * dn[k];
				v1 /= d[k].st + 1;
			}

			PIL t(f[i - 1][j].st + 1, f[i - 1][j].nd + a[i]);
			if (f[i][v2] > t)
				f[i][v2] = t, pre[i][v2] = j;
		}
	}

	if (f[n][tot - 1].st > n)
		puts("-1");
	else{
		printf("%d\n", f[n][tot - 1].st);
		for (int i = n, j = tot - 1; i >= 1; j = pre[i][j], --i)
			if (pre[i][j] != j){
				if (j != tot - 1)
					putchar(' ');
				printf("%d", i);
			}
		puts("");
	}
	return 0;
}