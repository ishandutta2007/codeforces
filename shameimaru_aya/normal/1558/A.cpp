#include <bits/stdc++.h>
using namespace std;
int T , a , b , L , R; 
int main()
{
	cin >> T;
	while(T--)
	{
		scanf("%d%d" , &a , &b);
		int qwq = abs(a - b);
		L = qwq / 2; R = a + b - qwq / 2;
		if((a + b) % 2 == 0) 
		{
			printf("%d\n" , (R - L) / 2 + 1);
			for(int i = L ; i <= R ; i += 2 ) printf("%d " , i);
		}
		else
		{
			printf("%d\n" , (R - L) / 1 + 1);
			for(int i = L ; i <= R ; i++ ) printf("%d " , i);
		}
		printf("\n");
	}
	return 0;
}
/*

*/