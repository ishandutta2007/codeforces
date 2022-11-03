#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2E5 + 10, S = 26, NN = 3E4 + 10;

int n, m, s0;
char s[N];
int a[S];

int f[NN];

int main(){
	int cas;
	scanf("%d", &cas);
	while (cas--){
		scanf("%d%d%d", &n, &m, &s0);
		scanf("%s", s);
		fill_n(a, S, 0);
		for (int i = 0; i < s0; ++i)
			++a[s[i] - 'A'];

		ll ans = n * m;
		int sum = 0;
		for (int i = 0; i < S; ++i)
			sum += a[i];

		for (int i = 0; i < S; ++i){
			int tsum = sum - a[i];
			f[0] = 1;
			fill_n(f + 1, n, 0);
			for (int j = 0; j < S; ++j)
				if (i != j){
					int w = a[j];
					for (int k = n; k >= w; --k)
						f[k] |= f[k - w];
				}
			for (int j = 0; j <= n; ++j)
				if (f[j]){
					if (j >= n && (tsum - j) + a[i] >= m
						|| j + a[i] >= n && (tsum - j) >= m)
						ans = 0;
					else if (j < n && (tsum - j) <= m)
						ans = min<ll>(ans, (n - j) * (m - (tsum - j)));
				}
		}
		printf("%lld\n", ans);
	}
	return 0;
}