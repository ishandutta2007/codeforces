#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;

int n;
int a[MAXN], b[MAXN], c[MAXN];
int val[MAXN];

ll ans;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

void work(int d){
	for (int i = 0; i < d; ++i)
		val[i] = a[i];
	for (int i = d; i < n; ++i)
		val[i % d] = max(val[i % d], a[i]);

	for (int i = 1; i <= n; ++i)
		c[i] = c[i - 1] + (b[i] == d);

	int start = -1;
	for (int i = 0; i < n; ++i)
		if (a[i] != val[i % d]){
			start = i;
			break;
		}
	if (start == -1){
		ans += c[n] * (ll)n;
		return;
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		ans += c[cnt = a[(i + start) % n] == val[(i + start) % d] ? cnt + 1 : 0];
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		b[i + 1] = gcd(i + 1, n);
	}
	if (n > 1)
		work(1);
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0){
			work(i);
			if (i * i < n)
				work(n / i);
		}
	printf("%I64d\n", ans);
	return 0;
}