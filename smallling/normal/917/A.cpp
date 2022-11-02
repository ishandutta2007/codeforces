#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

char s[N];
bool flag[N][N];

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1), ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int cnt1 = 0, cnt2 = 0;
		for(int j = i; j <= n; j++)
		{
			if(s[j] == '(')cnt1++;
			if(s[j] == '?')cnt2++;
			if(s[j] == ')')
			{
				if(cnt1 > 0)cnt1--;
				else
				{
					if(cnt2 > 0)cnt2--;
					else break;
				}
			}
			if(cnt2 >= cnt1 && (cnt2 - cnt1) % 2 == 0)flag[i][j] = 1;
		}
	}
	reverse(s + 1, s + 1 + n);
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '(')s[i] = ')';
		else if(s[i] == ')')s[i] = '(';
	}
	for(int i = 1; i <= n; i++)
	{
		int cnt1 = 0, cnt2 = 0;
		for(int j = i; j <= n; j++)
		{
			if(s[j] == '(')cnt1++;
			if(s[j] == '?')cnt2++;
			if(s[j] == ')')
			{
				if(cnt1 > 0)cnt1--;
				else
				{
					if(cnt2 > 0)cnt2--;
					else break;
				}
			}
			if(cnt2 >= cnt1 && (cnt2 - cnt1) % 2 == 0)ans += flag[n - j + 1][n - i + 1];
		}
	}
	printf("%d\n", ans);
}