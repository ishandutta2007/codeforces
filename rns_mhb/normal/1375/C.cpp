#include <bits/stdc++.h>
using namespace std;

#define N 333

int a[N][N], b[N][N];

int main() {
	int t;
	cin >> t;
	while(t --) {
		int n;
		cin >> n;
		vector <int> a(n+1);
		for(int i = 1; i <= n; i ++) cin >> a[i];
		if(n == 1) {
			puts("YES");
			continue;
		}
        if(a[1] < a[n]) {
			puts("YES");
        }
        else puts("NO");
	}
}