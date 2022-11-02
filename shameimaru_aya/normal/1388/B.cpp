#include<bits/stdc++.h>
using namespace std;
int T , n;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		int qwq = (n + 3) / 4;
		for(int i = 1 ; i <= n - qwq ; i++ ) printf("9");
		for(int i = 1 ; i <= qwq ; i++ ) printf("8");
		printf("\n");
	}
	return 0;
}