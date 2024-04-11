#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define maxn 1005
#define sq 355
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int r[maxn], c[maxn];
int cnt;
int os[maxn][4];
void push(int a, int b, int c, int d)
{
	os[cnt][0] = a, 
	os[cnt][1] = b;
	os[cnt][2] = c;
	os[cnt][3] = d;
	cnt++;
}
void work(int n)
{
	if(n == 0) return;
	if(r[n] == n && c[n] == n) work(n - 1);
	else
	{
		for(int j = 1; j <= n - 1; j++)
			if(r[j] == n) r[j] = r[n];
		for(int j = 1; j <= n - 1; j++)
			if(c[j] == n) c[j] = c[n];
		work(n - 1);
		push(r[n], n, n, c[n]);	
	} 
}
int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		scanf("%d", &r[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	work(n);
	cout<<cnt<<endl;
	for(int i = 0; i < cnt; i++)
		printf("%d %d %d %d\n", os[i][0], os[i][1], os[i][2], os[i][3]);
	return 0;
} 
/*
2 1 1 5

 
*/