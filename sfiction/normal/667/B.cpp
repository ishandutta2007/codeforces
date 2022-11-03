#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
	int n, val = 0;
	ll s = 0;
	scanf("%d", &n);
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		s += t;
		val = max(val, t);
	}
	s -= val;
	printf("%I64d\n", max(0ll, val + 1 - s));
	return 0;
}