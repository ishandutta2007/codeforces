#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long
#define ld double
#define mod 1000000007
using namespace std;
char s[maxn], a[maxn], b[maxn];
int k;
int eg[2][2]; // x <= y
int tr[27], fl[27];
int ans[27];
int n;
int fls = 0;
int set(int x, int y)
{
	if(tr[x] != -1 && tr[x] != y) return 0;	
	if(fl[y] && tr[x] == -1) return 0;
	tr[x] = y, fl[y] = 1;
	return 1;
}
void wkm()
{
	//
	int pl = 0;
	while(fl[pl] && pl < k) pl++;
	for(int i = 0; i < k; i++)
	{
		if(tr[i] == -1)
		{
			tr[i] = pl, fl[pl] = 1;
			while(fl[pl] && pl < k) pl++;
		}
		ans[i] = tr[i];
	}
}
void work1(int pl)
{
	if(fls) return;
	if(pl == n) 
	{
		fls = 1;
		wkm();
		return ;
	}
	for(int j = a[pl] - 'a'; j < k; j++)
	{
		if(fls) return;
		int l1 = tr[s[pl] - 'a'], l2 = fl[j];
		int ns = set(s[pl] - 'a', j);
		if(ns)
			if(j == a[pl] - 'a') work1(pl + 1);
			else 
			{
				fls = 1;
				wkm();
			}
		fl[j] = l2, tr[s[pl] - 'a'] = l1;
	}
}
void work2(int pl)
{
	if(fls) return;
	if(pl == n) 
	{
		fls = 1;
		wkm();
		return ;
	}
	for(int j = 0; j <= b[pl] - 'a'; j++)
	{
		if(fls) return;
		int l1 = tr[s[pl] - 'a'], l2 = fl[j];
		int ns = set(s[pl] - 'a', j);
		if(ns)
			if(j == b[pl] - 'a') work2(pl + 1);
			else 
			{
				fls = 1;
				wkm();
			}
		fl[j] = l2, tr[s[pl] - 'a'] = l1;
	}
}
void work(int pl)
{
//	cout<<"WOK"<<pl<<endl;
	if(pl == n)
	{
		fls = 1;
		wkm();
		return ;
	}
	if(a[pl] == b[pl])
	{
		int n1 = set(s[pl] - 'a', a[pl] - 'a');
		if(!n1) return ;
		else
			work(pl + 1);
	}
	else
	{
		for(int j = a[pl] - 'a'; j <= b[pl] - 'a'; j++)
		{
			int l1 = tr[s[pl] - 'a'], l2 = fl[j];
			if(fls) return ;
			int ns = set(s[pl] - 'a', j);
			if(ns)
				if(j == a[pl] - 'a') work1(pl + 1);
				else if(j == b[pl] - 'a') work2(pl + 1);
				else
				{
					fls = 1;
					wkm();
				}
			fl[j] = l2, tr[s[pl] - 'a'] = l1;
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		memset(fl, 0, sizeof(fl));
		memset(tr, -1, sizeof(tr));
		fls = 0;
		scanf("%d", &k);
		scanf("%s", s);
		scanf("%s", a);
		scanf("%s", b);
		n = strlen(s);
		work(0);
		if(fls)
		{
			printf("YES\n");
			for(int i = 0; i < k; i++)
				printf("%c", char(ans[i] + 'a'));
			printf("\n");
		}
		else printf("NO\n");
	}
	return 0;
}