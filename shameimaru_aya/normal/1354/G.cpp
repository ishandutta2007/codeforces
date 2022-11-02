#include <bits/stdc++.h>
using namespace std;
int T , n , m , k , ans;
string s;
void binary( int l , int r ) //9
{
	if(l > r)
	{
		printf("! %d\n" , ans);
		fflush(stdout);
		return ;
	}
	int mid = l + r >> 1;
	int len = mid - l + 1;
	printf("? %d %d\n" , len , len); fflush(stdout);
	for(int i = 1 ; i <= len ; i++ )
	printf("%d " , i) , fflush(stdout);
	printf("\n"); fflush(stdout);
	for(int i = 1 ; i <= len ; i++ )
	printf("%d " , i + l - 1) , fflush(stdout);
	printf("\n"); fflush(stdout);
	cin >> s;
	if(s == "FIRST")
	{
		ans = mid;
		binary(l , mid - 1);
	}
	else binary(mid + 1 , r);
	return ;
}
int main()
{
	srand((unsigned)time(NULL));
	scanf("%d" , &T);
	while(T--)
	{
		bool f = 0;
		scanf("%d%d" , &n , &m);
		for(int i = 1 ; i <= 31 ; i++ ) //31
		{
			int r = rand() % n + 1;
			while(r == 1) r = rand() % n + 1;
			printf("? 1 1\n1 %d\n" , r); fflush(stdout);
			cin >> s;
			if(s == "SECOND")
			{
				printf("! 1\n"); fflush(stdout); f = 1;
				break;
			}
		}
		if(f) continue;
		for(int i = 0 ; i <= 9 ; i++ ) //10
		{
			if((1 << i + 1) > n)
			{
				k = i;
				break;
			}
			int len = 1 << i;
			printf("? %d %d\n" , len , len); fflush(stdout);
			for(int j = 1 ; j <= len ; j++ )
			printf("%d " , j) , fflush(stdout);
			printf("\n"); fflush(stdout);
			for(int j = 1 ; j <= len ; j++ )
			printf("%d " , j + len) , fflush(stdout);
			printf("\n"); fflush(stdout);
			cin >> s;
			if(s == "FIRST")
			{
				k = i;
				break;
			}
		}
		binary((1 << k) + 1 , min(1 << k + 1 , n));
	}
	return 0;
}