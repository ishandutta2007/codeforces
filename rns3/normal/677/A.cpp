#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("1.in", "r", stdin);
	int n, h;
	scanf("%d %d", &n, &h);
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		int x;
		scanf("%d", &x);
		if(x <= h) ans ++;
		else ans += 2;
	}
	cout << ans << endl;
}