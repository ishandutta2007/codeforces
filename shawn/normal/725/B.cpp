#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll read () {
	ll x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ? -1 : 1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

ll ans , pos , len , num , v[6] = {4ll , 5ll , 6ll , 3ll , 2ll , 1ll};

char s[100];

void cal (int x) {
	if (x == 0) {
		ans -= 3ll;
		pos = s[len] - 97;
		ans -= 6 - v[pos];
	}
	
	if (x == 1) {
		pos = s[len] - 97;
		ans += v[pos];
	}
	
	if (x == 3) {
		pos = s[len] - 97;
		ans += v[pos];
	}
	
	if (x == 2) {
		ans += 7ll;
		pos = s[len] - 97;
		ans += v[pos];
	}
	
}

int main() {
	scanf("%s" , s + 1);
	len = strlen(s + 1);
	for (int i = 1 ; i < len ; i ++) num = num * 10ll + 1ll * (s[i] - 48);
	ans = (num / 4ll * 16ll);	
	cal(num % 4ll);
	printf("%I64d\n" , ans);
	return 0;
}