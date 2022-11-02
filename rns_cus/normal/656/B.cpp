#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
	int c = __gcd(a, b);
	return a /c * b;
}

#define N 100
int a[N], b[N];

int main() {
	int n;
	int x = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i ++) scanf("%d", &b[i]);
	for(int i = 0; i < n; i ++) x = lcm(x, a[i]);
	int cnt = 0;
	for(int i = 0; i < x; i ++) {
		bool ok = false;
        for(int j = 0; j < n; j ++) if(i % a[j] == b[j]) {
        	ok = true;
			break;
        }
        if(ok) cnt ++;
	}
	printf("%.8lf\n", 1.0 * cnt / x);
	return 0;

}