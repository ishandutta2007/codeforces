#include<bits/stdc++.h>
using namespace std;
int h , n , x , cnt[300000] , maxx , sec , id1 , id2;
inline int random()
{
	return (rand() << 15) + rand();
}
int main() 
{
	srand((unsigned)time(NULL));
	scanf("%d" , &h); n = (1 << h) - 1;
	for(int i = 1 ; i <= 422 ; i++ )
	{
		int a = random() % n + 1 , b = random() % n + 1 , c = random() % n + 1;
		while(a == b || b == c || a == c)
			a = random() % n + 1 , b = random() % n + 1 , c = random() % n + 1;
		printf("? %d %d %d\n" , a , b , c); fflush(stdout);
		scanf("%d" , &x); cnt[x]++;
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		if(cnt[i] > maxx) sec = maxx , id2 = id1 , maxx = cnt[i] , id1 = i;
		else if(cnt[i] > sec) sec = cnt[i] , id2 = i;
	} 
	for(int i = 1 ; i <= n ; i++ )
	{
		if(i == id1 || i == id2) continue;
		printf("? %d %d %d\n" , id1 , id2 , i); fflush(stdout);
		scanf("%d" , &x); 
		if(x == i)
		{
			printf("! %d" , i); fflush(stdout);
			return 0;
		}
	}
    return 0;
}
/*
5
2 0 2 0 
*/