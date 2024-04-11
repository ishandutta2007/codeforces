#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 300005
#define maxnod 10000000
#define ll long long 
using namespace std;
int nx[maxnod][2], sz[maxnod];
int ncnt;
int a[maxn], p[maxn];
int root;
void ins(int x, int tp)
{
	int npl = root;
	sz[root] += tp;
	for(int i = 29; i >= 0; i--)
	{
		if(!nx[npl][(x >> i) & 1])
			nx[npl][(x >> i) & 1] = ncnt++;
		int ed = nx[npl][(x >> i) & 1];
		sz[ed] += tp, npl = ed;
	}
}
int fd(int x)
{
	int npl = root;
	int nans = x;
	for(int i = 29; i >= 0; i--)
	{
		int ns = (x >> i) & 1;
		if(nx[npl][ns] && sz[nx[npl][ns]]) npl = nx[npl][ns];
		else npl = nx[npl][ns ^ 1], nans ^= (1 << i);
	}
	return nans;
}
int main()
{
	int n;
	root = ncnt++;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &p[i]), ins(p[i], 1);
	for(int i = 1; i <= n; i++)
	{
		int ns = fd(a[i]);
	//	cout<<"FIND"<<" "<<ns<<endl;
		ins(ns, -1);
		a[i] ^= ns;
		printf("%d ", a[i]);
	}
	return 0;
}