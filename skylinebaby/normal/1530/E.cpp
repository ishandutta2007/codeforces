#include<bits/stdc++.h>
using namespace std;
char a[112345];
int dp[30];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		cin >> a;
		int n = strlen(a);
		for(int i = 0; i < 26; i++) 
		{
			//if(dp[i] != 0) printf("%rjkqljnrelk\n");
			dp[i] = 0;
		}
		for(int i = 0; i < n; i++)
		{
			dp[a[i] - 'a']++;
		}
		int mn = 26;
		int mn2 = 26;
		int fk = 26;
		int k = 0;
		for(int i = 0; i < 26; i++)
		{
			if(dp[i] > 0)
			{
				mn = min(mn, i);
				if(i > mn) mn2 = min(mn2, i);
				k++;
				if(dp[i] == 1) fk = min(fk, i);
			}
		}
		if(k == 1)
		{
			for(int i = 0; i < dp[mn]; i++) 
			{
				printf("%c", 'a' + mn);
			}
			dp[mn] = 0;
			printf("\n");
		}
		else if (fk < 26)
		{
			printf("%c", 'a' + fk);
			dp[fk]--;
			for(int i = 0; i < 26; i++)
			{
				for(int j = 0; j < dp[i]; j++)
				{
					printf("%c", 'a' + i);
				}
				dp[i] = 0;
			}
			printf("\n");
		}
		else if(dp[mn] * 2 <= n + 2)
		{
			for(int i = 0; i < 2; i++) printf("%c", 'a' + mn);
			dp[mn] -= 2;
			for(int i = mn + 1; i < 26; i++)
			{
				for(int j = 0; j < dp[i]; j++)
				{
					if(dp[mn]) 
					{
						printf("%c%c", 'a' + i, 'a' + mn);
						dp[mn]--;
					}
					else printf("%c", 'a' + i);	
				}
				dp[i] = 0;
			}
			printf("\n");			
		}
		else if(k == 2)
		{
			printf("%c", 'a' + mn);
			for(int j = 0; j < dp[mn2]; j++)
			{
				printf("%c", 'a' + mn2);
			}
			for(int j = 0; j < dp[mn] - 1; j++)
			{
				printf("%c", 'a' + mn);
			}
			dp[mn] = 0;
			dp[mn2] = 0;
			printf("\n");			
		}
		else
		{
			printf("%c%c", 'a' + mn, 'a' + mn2);
			dp[mn] --;
			dp[mn2] --;
			for(int i = 0; i < 26; i++)
			{	
				if(i == mn2) i++;
				for(int j = 0; j < dp[i]; j++)
				{				 
					printf("%c", 'a' + i);
					if(dp[mn2] && i != mn)
					{
						for(int k = 0; k < dp[mn2]; k++)
						{
							printf("%c", 'a' + mn2);
						}
						dp[mn2] = 0;
					}
				}
				dp[i] = 0;
			}
			printf("\n");
		}
	}
	return 0;
}