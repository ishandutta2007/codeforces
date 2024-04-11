#include <cstdio>
#include <cstring>

typedef long long ll;

const int MAXN = 1E5 + 100;
const ll MOD = 1E9 + 7;

char s[MAXN];

ll pm(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1){
		if (n & 1)
			ret = ret * e % m;
		e = e * e % m;
	}
	return ret;
}

int main(){
	int cnt[26];
	int n;
	scanf("%d%s", &n, s);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i){
		++cnt[s[i] - 'A'];
	}
	int m = 0, cm = 0;
	for (int i = 0; i < 26; ++i){
		if (m < cnt[i]){
			m = cnt[i];
			cm = 0;
		}
		cm += m == cnt[i];
	}
	printf("%d", (int)pm(cm, n));
	return 0;
}