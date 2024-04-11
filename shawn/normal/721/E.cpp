#include <bits/stdc++.h>

using namespace std;

#define N 100005
int m , n , p , now , ans , x , y , t;
int f[N] , g[N];

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

void update(int k , int w , int x , int y) {
	if (w + (y - x) / p > f[k]) {
		f[k] = w + (y - x) / p;
		g[k] = x + (y - x) / p * p;
	}else if (w + (y - x) / p == f[k]) g[k] = min(g[k] , x + (y - x) / p * p);
}

int main() {
	m = read() , n = read() , p = read() , t = read();
	g[0] = -t;
	for (int i = 1 ; i <= n ; i ++) {
		x = read() , y = read();
		if (now) now --;
		for ( ; now < i && g[now] + t <= y ; now ++) {
			if (g[now] + t <= x) update(i , f[now] , x , y);
			else update(i , f[now] , g[now] + t , y);
		}
		ans = max(ans , f[i]);
		if (f[i - 1] > f[i]) f[i] = f[i - 1] , g[i] = g[i - 1];
		else if (f[i - 1] == f[i]) g[i] = min(g[i] , g[i - 1]);
	}
	printf("%d\n", ans);
	return 0;
}