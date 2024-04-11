#include <bits/stdc++.h>
using namespace std;
int n , tot , x[550000] , y[550000] , k;
queue< int > q[30];
inline void match( int a , int b )
{
	for(int k = 2 ; k <= b - a + 1 ; k <<= 1 )
		for(int i = a ; i <= b ; i += k )
			for(int j = i ; j < i + k / 2 ; j++ )
				x[++tot] = j , y[tot] = j + k / 2;
}
int main()
{
	scanf("%d" , &n);
	int k = 1 << (int)log2(n - 1);
	match(1 , k); match(n - k + 1 , n);
	printf("%d\n" , tot);
	for(int i = 1 ; i <= tot ; i++ ) printf("%d %d\n" , x[i] , y[i]);
    return 0;
}