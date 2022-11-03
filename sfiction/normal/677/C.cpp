#include <cctype>
#include <cstdio>

typedef long long ll;

const ll MOD = 1E9 + 7;

int getNum(char c){
	return isdigit(c) ? c - '0'
			: isupper(c) ? c - 'A' + 10
			: islower(c) ? c - 'a' + 36
			: c == '-' ? 62
			: 63;
}

int a[64];

int main(){
	a[0] = 1;
	for (int i = 1; i < 64; ++i)
		a[i] = a[i >> 1] * (i & 1 ? 3 : 1);

	ll ans = 1;
	for (char c; (c = getchar()) != EOF && isgraph(c); (ans *= a[0x3f ^ getNum(c)]) %= MOD);
	printf("%d\n", (int)ans);
	return 0;
}