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
struct tr
{
	int l[2], u[2];
	tr(){l[0] = l[1] = -1e9, u[0] = u[1] = 1e9;}
};
tr u(tr a, tr b)
{
	tr n1;
	for(int i = 0; i < 2; i++)
		n1.l[i] = max(a.l[i], b.l[i]), 
		n1.u[i] = min(a.u[i], b.u[i]);
	return n1;
} 
tr a[maxn];
tr p[maxn], e[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d%d%d", &a[i].l[0], &a[i].l[1], &a[i].u[0], &a[i].u[1]);
	p[1] = a[1];
	for(int i = 2; i <= n; i++)
		p[i] = u(a[i], p[i - 1]);
	e[n] = a[n];
	for(int i = n - 1; i >= 0; i--)
		e[i] = u(a[i], e[i + 1]);
	for(int i = 1; i <= n; i++)
	{
		tr n1 = u(p[i - 1], e[i + 1]);
		if(n1.l[0] <= n1.u[0] && n1.l[1] <= n1.u[1])
		{
			cout<<n1.l[0]<<" "<<n1.l[1]<<endl;
			break;
		}
	}
	return 0;
}