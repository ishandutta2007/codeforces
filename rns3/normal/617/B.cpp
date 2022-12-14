#include <bits/stdc++.h>
using namespace std;

int a[101];
unsigned long long f[101];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	f[0] = 1;
	int i;
	for(i = 1; i <= n; i ++) if(a[i] == 1) break;
	if(i == n + 1) return puts("0");
	f[i] = 1;
	for(; i <= n; i ++) {
        if(a[i] == 1) {
			for(int j = i - 1; j; j --) {
				f[i] += f[j];
				if(a[j] == 1) break;
			}
        }
        else f[i] = f[i-1];
	}
	cout << f[n] << endl;
}