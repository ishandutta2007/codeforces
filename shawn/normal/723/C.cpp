#include <bits/stdc++.h>

#define N 3000

using namespace std;

int n , m , ans , a[N] , b[N] , id = 1;

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

int main() {
	n = read() , m = read();
	for (int i = 1 ; i <= n; i ++){
		a[i] = read();
		if (a[i] <= m) b[a[i]] ++;
	}
	for (int i = 1 ; i <= m ; i ++) if (b[i] < n/m) ans += n/m - b[i];
	for (int i = 1 ; i <= n ; i ++) {
		while (b[id] >= n/m && id <= m) id ++;
		if (id > m) break;
		if (a[i] <= m) {
			if (b[a[i]] > n/m) b[a[i]] -- , a[i] = id , b[id] ++;
		} else a[i] = id , b[id] ++;
	}
	printf("%d %d\n" , n/m , ans);
	for(int i=1 ; i <= n ; i++)printf("%d " , a[i]);
	return 0;
}