#include <bits/stdc++.h> 
using namespace std;
int n , m , k , x = 1 , y = 1 , p = 1 , num;
inline void work( int num )
{
	while(num--)
	{
		printf("%d %d " , x , y);
		x += p;
		if(x > n) x = n , y++ , p = -1;
		if(x < 1) x = 1 , y++ , p = 1;
	}
	printf("\n");
	return ;
}
int main()
{
	scanf("%d%d%d" , &n , &m , &k); num = n * m;
	for(int i = 1 ; i < k ; i++ )
	{
		printf("2 ");
		work(2); num -= 2;
	}
	printf("%d " , num);
	work(num);
	return 0;
}
/*

*/