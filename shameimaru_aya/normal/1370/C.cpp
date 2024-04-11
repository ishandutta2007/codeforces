#include<bits/stdc++.h>
using namespace std;
int T , n , tot , qaq; 
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		if(n == 1)
		{
			printf("FastestFinger\n");
			continue;
		}
		if(n % 2)
		{
			printf("Ashishgup\n");
			continue;
		}
		tot = 0; qaq = 1;
		int qwq = sqrt(n);
		for(int i = 2 ; i <= qwq ; i++ )
		{
			while(n % i == 0) 
			{
				n /= i;
				if(i % 2) tot++;
				else qaq *= i;
			}
		}
		if(n > 1)
		{
			if(n % 2) tot++;
			else qaq *= n;
		}
		if(tot == 0)
		{
			if(qaq == 2) printf("Ashishgup\n");
			else printf("FastestFinger\n");
			continue;
		}
		if(tot == 1)
		{
			if(qaq == 2) printf("FastestFinger\n");
			else printf("Ashishgup\n");
			continue;
		}
		else printf("Ashishgup\n");
	}
	return 0;
}