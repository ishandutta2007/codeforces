#include <bits/stdc++.h>
using namespace std;

int a[1001];

int main() {
	int n;
	scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int pos1, pos2;
    for(int i = 1; i <= n; i ++) {
		if(a[i] == 1) pos1 = i;
		if(a[i] == n) pos2 = i;
    }
	int ans = 0;
	ans = max(ans, abs(pos1 - pos2));
	ans = max(ans, abs(pos1 - 1));
	ans = max(ans, abs(pos1 - n));
	ans = max(ans, abs(pos2 - 1));
	ans = max(ans, abs(pos2 - n));
	cout << ans << endl;
}