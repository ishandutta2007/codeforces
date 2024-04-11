/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 448D
 */
#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull n, m, k;

ull count(ull num){
	ull ret = 0;
	for (int i=1;i<=n;++i)
		ret += min(m, num / i);
	return ret;
}

int main(){
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	ull high = n * m + 1, low = 1, mid;
	while (high > low){
		mid = (high + low) >> 1;
		if (count(mid) >= k)
			high = mid;
		else
			low = mid + 1;
	}
	printf("%I64u", low);
	return 0;
}