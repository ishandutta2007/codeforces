#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10, MAXA = 2E5 + 10;

int n;
int cnt[MAXA];
ll s1[MAXA], s2[MAXA];

inline ll count(int l, int r){
	return (s2[r] - s2[l]) - (s1[r] - s1[l]) * l;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		++cnt[t];
	}
	for (int i = 1; i < MAXA; ++i){
		s1[i] = s1[i - 1] + cnt[i];
		s2[i] = s2[i - 1] + cnt[i] * (ll)i;
	}
	ll ans = 0;
	for (int i = 1; i < MAXA; ++i){
		if (cnt[i] == 0)
		   continue;

		ll tot = s2[MAXA - 1] - s2[i - 1];
		for (int j = i; j < MAXA; j += i)
			tot -= count(j, min(j + i - 1, MAXA - 1));
		ans = max(ans, tot);
	}
	printf("%lld\n", ans);
	return 0;
}