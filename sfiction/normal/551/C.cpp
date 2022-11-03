/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 551C
 */
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10;

int n, m;
int a[MAXN];

bool check(ll limit){
	int j = n;
	ll k = a[j];

	for (int i=0;i<m;++i){
		ll res = limit - j;

		while (res >= k){
			if (j == 0)
				return true;
			res -= k;
			k = a[--j];
		}

		k -= res;
	}

	return false;
}

int main(){
	scanf("%d%d", &n, &m);
	ll high = n + 1, low = 0, mid;
	for (int i=1;i<=n;++i){
		scanf("%d", &a[i]);
		high += a[i];
		if (a[i])
			low = i;
	}
	n = low;

	while (high > low){
		mid = high + low >> 1;
		if (check(mid))
			high = mid;
		else
			low = mid + 1;
	}

	printf("%I64d", low);

	return 0;
}