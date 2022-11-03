#include <cstdio>

typedef long long ll;

const int MAXN = 2E5 + 10;

int a[MAXN];
int b[MAXN], c[MAXN];
int cnt[32];

int main(){
	int n;
	scanf("%d", &n);
	ll s = 0;
	for (int i = 0; i < n; ++i)
		scanf("%d", b + i), s += b[i];
	for (int i = 0; i < n; ++i)
		scanf("%d", c + i), s += c[i];
	if (s % (n << 1)){
		puts("-1");
		return 0;
	}
	s /= n << 1;
	for (int i = 0; i < n; ++i){
		a[i] = b[i] + c[i] - s;
		if (a[i] % n){
			puts("-1");
			return 0;
		}
		a[i] /= n;
		for (int j = 0; j < 31; ++j)
			cnt[j] += a[i] >> j & 1;
	}
	for (int i = 0; i < n; ++i){
		ll t = 0;
		for (int j = 30; j >= 0; --j){
			t <<= 1;
			if (a[i] >> j & 1)
				t += cnt[j];
		}
		if (t != b[i]){
			puts("-1");
			return 0;
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d%c", a[i], "\n "[i + 1 < n]);
	return 0;
}