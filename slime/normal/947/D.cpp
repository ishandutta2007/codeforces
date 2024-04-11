#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define maxnod 10000000
#define ll long long 
using namespace std;
char inp[maxn];
int cnt[2][maxn];
int lpl[2][maxn];
char otp[maxn];
int ncnt = 0;
int main()
{
	for(int i = 0; i < 2; i++)
	{
		scanf("%s", inp + 1);
		int l = strlen(inp + 1);
		for(int j = 1; j <= l; j++)
		{
			cnt[i][j] = cnt[i][j -  1];
			lpl[i][j] = lpl[i][j - 1];
			if(inp[j] == 'B' || inp[j] == 'C')
				cnt[i][j]++, lpl[i][j] = j;
		}
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		int cnt0 = cnt[0][r1] - cnt[0][l1 - 1];
		int cnt1 = cnt[1][r2] - cnt[1][l2 - 1];
		int lst0 = max(lpl[0][r1], l1 - 1), 
		lst1 = max(lpl[1][r2], l2 - 1);
		int a0 = r1 - lst0, a1 = r2 - lst1;
		bool flag = 1;
		if(a0 < a1) flag = 0;
		if(a0 == r1 - l1 + 1 && a0 == a1 && a1 != r2 - l2 + 1) flag = 0;
		for(int j = 0; j <= 2; j++)
		{
			if((a0 - j - a1) % 3) continue;
			if(j != 0) cnt0 += 2;
			break;
		}
		if(cnt1 < cnt0) flag = 0;
		if((cnt1 - cnt0) & 1) flag = 0;
	//	cout<<flag<<endl;
		if(flag) otp[ncnt++] = '1';
		else otp[ncnt++] = '0';
		
	}
	for(int i = 0; i < ncnt; i++)
		putchar(otp[i]);
	return 0;
}