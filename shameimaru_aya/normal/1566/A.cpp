#include <bits/stdc++.h>
using namespace std;
int T , n , s;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &s);
		printf("%d\n" , s / (n / 2 + 1));
	}
	return 0;  
}
/*
*/