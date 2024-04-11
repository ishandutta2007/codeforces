#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		long long a, b, x;
		scanf("%lld %lld %lld", &a, &b, &x);
		int answer = 0;
		while(true) {
			if(a > b) {
				swap(a, b);
			}
			if(x == b-a) {
				answer = 1;
			}
			if(a == 0) {
				break;
			}
			if(x <= b && x%a == b%a) {
				answer = 1;
			}
			b %= a;
		}
		if(answer) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}