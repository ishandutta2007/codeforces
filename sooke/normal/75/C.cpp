#include <cstdio>
#include <cmath>

int Gcd(int x , int y){
	return y == 0 ? x : Gcd(y , x % y);
}

int a , b , n , p , m , cn , c[10001];

inline int BinarySearch(int d){
	int ans = cn + 1;
	for(int l = 1 , r = cn , mid ; l <= r ;){
		mid = l + r >> 1;
		if(c[mid] <= d)
			l = mid + 1 , ans = mid;
		else
			r = mid - 1;
	}
	return ans;
}

int main(){
	scanf("%d%d" , &a , &b);
	n = Gcd(a , b);
	p = floor(sqrt(n));
	for(int i = 1 ; i <= p ; i++)
		if(n % i == 0)
			c[++cn] = i;
	for(int i = p ; i >= 1 ; i--)
		if(n % i == 0)
			c[++cn] = n / i;
	scanf("%d" , &m);
	for(int i = 1 ; i <= m ; i++){
		int l , r , ans;
		scanf("%d%d" , &l , &r);
		ans = c[BinarySearch(r)];
		if(ans >= l && ans <= r)
			printf("%d\n" , ans);
		else
			printf("-1\n");
	}
	return 0;
}

// By Sooke.
// CF75C Modified GCD.