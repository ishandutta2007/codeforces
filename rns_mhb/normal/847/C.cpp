#include <bits/stdc++.h>
using namespace std;

int n;
long long m;

int main() {
	cin >> n >> m;
	long long tmp = 1ll *  n * (n - 1) / 2;
	if ( tmp < m ) {
		puts("Impossible"); return 0;
	}
	long long now = 0;
	int k = 0, t = 0;
	for (int i = 0; ; i ++) {
		if (now + i < m) {
			now += i;
			putchar('(');
			n --;
		}
		else {
			now = m - now;
			for (int j = i; j > now; j --) putchar(')');
			putchar('(');
			n --;
			for (int i = 0; i <= now; i ++) putchar(')');
			for (int i = 0; i < n; i ++) putchar('('), putchar(')');
			return 0;
		}
	}


}