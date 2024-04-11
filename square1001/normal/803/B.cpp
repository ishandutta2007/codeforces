#include <bits/stdc++.h>
using namespace std;
int n, x, d[200009];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		if(x != 0) d[i] = 999999999;
	}
	for(int i = 1; i < n; i++) d[i] = min(d[i], d[i - 1] + 1);
	for(int i = n - 2; i >= 0; i--) d[i] = min(d[i], d[i + 1] + 1);
	for(int i = 0; i < n; i++) printf("%d ", d[i]);
	return 0;
}