#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

int n , m , a[100100] , b[100100] , ans , sum;

bool vis[100100];

bool jud(int x) {
	memset(vis , 0 , sizeof vis);
	sum = 0;
	for (int i = x ; i ; i --) {
		if (a[i] && vis[a[i]] == 0) {
			vis[a[i]] = 1;
			sum += b[a[i]];
		}else if (sum) sum --;
	}
	if (sum != 0) return 0;
	for (int i = 1 ; i <= m ; i ++) if (vis[i] == 0) return 0;
	return 1;
}

int main() {
	n = read() , m = read();
	for (int i = 1 ; i <= n ; i ++) a[i] = read();
	for (int i = 1 ; i <= m ; i ++) b[i] = read();
	int l = 0 , r = n; 
	while (l <= r) {
		int mid = l + r >> 1;
		if (jud(mid)) r = mid - 1 , ans = mid;
		else l = mid + 1;
	}
	printf("%d\n" , ans ? ans : -1);
	return 0;
}