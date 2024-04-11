#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2005
#define ll long long
using namespace std;
int lst[maxn][maxn];
char inp[maxn][maxn];
int n, k;
bool flag[26];
int fr[maxn][maxn];
bool check(int a, int b)
{
	if(a > n || b > n) return 0;
	if(a <= 0 || b <= 0 )return 0;
	return 1;
}
char otp[maxn * 2];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%s", inp[i] + 1);
	memset(lst, -1, sizeof(lst));

	if(k && inp[1][1] != 'a')
		k--, inp[1][1] = 'a';	
	lst[1][1] = k;
	for(int i = 2; i <= n * 2; i++)
	{
		int nss = 100;
		for(int j = 1; j <= i - 1; j++)
		{
			if(!check(j, i - j)) continue;
			if(lst[j][i - j] == -1) continue;
			for(int k = 0; k < 2; k++)
			{
				int edx = j, edy = i - j;
				if(k) edx++;
				else edy++;
				if(!check(edx, edy)) continue;
				int ns = inp[edx][edy] - 'a';
				if(lst[j][i - j]) ns = 0;
				nss = min(nss, ns);
			}
		}
	//	cout<<i<<" "<<nss<<endl;
		for(int j = 1; j <= i - 1; j++)
		{
			if(!check(j, i - j)) continue;
			if(lst[j][i - j] == -1) continue;
			for(int k = 0; k < 2; k++)
			{
				int edx = j, edy = i - j;
				if(k) edx++;
				else edy++;
				if(!check(edx, edy)) continue;
				int ns = inp[edx][edy] - 'a';
				if(lst[j][i - j]) ns = 0;
				if(ns != nss) continue;
				int nlst = lst[j][i - j];
				if(nlst && inp[edx][edy] != 'a')
					nlst--;
				if(nlst > lst[edx][edy])
				{
					lst[edx][edy] = nlst;
					fr[edx][edy] = j;
				//	cout<<edx<<" "<<edy<<" "<<j<<e
				}
			}
		}
	}
//	cout<<"ASDFAS"<<endl;
	int ocnt = 0;
	int nx = n, ny = n;
	while(nx != 1 || ny != 1)
	{
		otp[ocnt++] = inp[nx][ny];
		int s = nx + ny - 1;
		nx = fr[nx][ny], ny = s - nx;
	}
	otp[ocnt++] = inp[1][1];
	for(int l = ocnt - 1; l >= 0 && k; l--)
		if(otp[l] != 'a')
			k--, otp[l] = 'a';
	for(int l = ocnt - 1; l >= 0; l--)
		printf("%c", otp[l]);
	return 0;
}