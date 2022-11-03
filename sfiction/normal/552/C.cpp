#include <cstdio>

int main(){
	int n, m, t;

	for (scanf("%d%d", &n, &m); m && ((t = m % n) <= 1 || t >= n - 1); m /= n)
		m += t > 1;
	puts(m ? "NO" : "YES");
}