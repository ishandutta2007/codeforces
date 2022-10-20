#include <cstdio>

inline int gcd(int x, int y){
	if(y == 0) return x;
	return gcd(y, x % y);
}

int main(){
	// freopen("cf1088a.in", "r", stdin);
	// freopen("cf1088a.out", "w", stdout);
	int x;
	scanf("%d", &x);
	for(int i=1; i<=x; i++)
		for(int j=1; j<=x; j++){
			if(i % j == 0 && i * j > x && i / j < x){
				printf("%d %d\n", i, j);
				return 0;
			}
		}
	puts("-1");
	return 0;
}