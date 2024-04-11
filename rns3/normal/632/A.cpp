#include <bits/stdc++.h>
using namespace std;
#define M 10000
typedef long long ll;


int n, p;
int a[M];

int main() {
	//freopen("A2.in", "r", stdin);
	scanf("%d", &n);
	scanf("%d", &p);
	char s[20];
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		a[i] = s[4] > 0;
	}
	ll answer = 0;
	ll m = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i]) {
			m = m * 2 + 1;
			answer += p * m / 2;
		} else {
			answer += p * m;
			m = m * 2;
		}
	}
	printf("%I64d\n", answer);
	return 0;
}