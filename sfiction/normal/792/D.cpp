#include <cstdio>

typedef long long ll;

const int MAXN = 1E5 + 10;

char s[MAXN];

int main(){
	ll n;
	int cas;
	scanf("%lld%d", &n, &cas);
	n = __builtin_ctzll(n + 1) - 1;
	while (cas--){
		ll u;
		scanf("%lld%s", &u, s);

		int l = __builtin_ctzll(u);
		for (int i = 0; s[i]; ++i){
			if (s[i] == 'U'){
				if (l == n)
					continue;
				if (u >> l + 1 & 1)
					u -= 1ll << l++;
				else
					u += 1ll << l++;
			}
			else{
				if (l == 0)
					continue;
				if (s[i] == 'L')
					u -= 1ll << --l;
				else
					u += 1ll << --l;
			}
		}

		printf("%lld\n", u);
	}
	return 0;
}