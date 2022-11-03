#include <cstdio>

typedef long long ll;

ll x, y;

ll gcd(ll a, ll b){
	return b ? gcd(b, a % b) : a;
}

void gcdPrint(ll a, ll b, char c){
	if (b == 0)
		return;
	if (a > b)
		printf("%I64d%c", (a - 1)/ b, c);
	gcdPrint(b, a % b, 'A' + 'B' - c);
}

int main(){
	scanf("%I64d%I64d", &x, &y);
	if (gcd(x, y) == 1)
		gcdPrint(x, y, 'A');
	else
		puts("Impossible");
	return 0;
}