#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXA = 3E6;

ll cnt[MAXA + 1], s[MAXA + 1];
ll f[MAXA + 1];

int main(){
	int n;
	scanf("%d", &n);
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		++cnt[t];
	}
	for (int i = 1; i <= MAXA; ++i)
		s[i] = s[i - 1] + cnt[i];
	for (int i = 1; i <= MAXA; ++i){
		int j = 1;
		for (int k = i; k <= MAXA; k += i, ++j)
			f[k] += cnt[i] * cnt[j];
		f[MAXA] += cnt[i] * (s[MAXA] - s[j - 1]);
		f[MAXA / i >= i ? i * i : MAXA] -= cnt[i];
	}
	for (int i = MAXA - 1; i >= 1; --i)
		f[i] += f[i + 1];

	int q;
	scanf("%d", &q);
	while (q--){
		int t;
		scanf("%d", &t);
		printf("%I64d\n", f[t]);
	}

	return 0;
}