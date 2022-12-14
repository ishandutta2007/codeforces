#include <bits/stdc++.h>

using namespace std;

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

int a , b , c , tmp , ans;

int main() {
	a = read() , b = read() , c = read();
	ans = 0x7f7f7f7f;
	for (int i = 1 ; i <= 200 ; i ++){
		tmp = abs(i - a) + abs(i - b) + abs(i - c);
		ans = min(ans , tmp);
	}
	printf("%d\n" , ans);
	return 0;
}