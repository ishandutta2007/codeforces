#include <bits/stdc++.h>

using namespace std;

int cnt[10];

void geta(int &len)
{
	char ch = getchar();
	while(ch < '0' || ch > '9')ch = getchar();
	while(ch >= '0' && ch <= '9')cnt[ch - '0']++, ch = getchar(), len++;
}

int check(long long b, long long nowans, int x, int num)
{
	if(x == 1 && num == 0)return 0;
	if(cnt[num] < 0)return 0;
	long long nowl = 1;
	for(int i = 9; i >= 0; i--)
	{
		for(int j = 1; j <= cnt[i]; j++)
		{
			nowans = nowans + nowl * i;
			nowl *= 10;
		}
	}
	return nowans <= b;
}

int main()
{
	int len = 0;
	long long b, nowans = 0, nowbase = 1;
	geta(len);
	scanf("%lld", &b);
	for(int i = 1; i < len; i++)
		nowbase *= 10;
	for(int i = 1; i <= len; i++)
	{
		for(int j = 9; j >= 0; j--)
		{
			nowans += j * nowbase;
			cnt[j]--;
			if(check(b, nowans, i, j))break;
			cnt[j]++; 
			nowans -= j * nowbase;
		}
		nowbase /= 10;
	}
	printf("%lld\n", nowans);
}