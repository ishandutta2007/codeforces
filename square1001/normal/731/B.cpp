#include <bits/stdc++.h>
using namespace std;
int n, a[200009];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	bool f = true;
	for(int i = 0; i < n; i++) {
		a[i] %= 2;
		if(a[i] == 1 && i < n - 1 && a[i + 1] >= 1) a[i + 1]--;
		else if(a[i] == 1) f = false;
	}
	puts(f ? "YES" : "NO");
	return 0;
}