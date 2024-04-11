#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define maxn 300005
#define ll long long
#define ld double
#define mod 1000000007
using namespace std;
const int s = 20;
int nx[maxn][s];
int pl[s];
int a[maxn];
int main()
{
	int n, q;
	cin>>n>>q;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < s; i++)
		pl[i] = n + 1;
	for(int i = n; i >= 1; i--)
	{
		for(int j = 0; j < s; j++)
			nx[i][j] = n + 1;
		for(int k = 0; k < s; k++)
			if(a[i] & (1 << k))
				if(pl[k] != n + 1)
					for(int u = 0; u < s; u++)
						nx[i][u] = min(nx[i][u], nx[pl[k]][u]);
		for(int j = 0; j < s; j++)	
			if(a[i] & (1 << j))
				pl[j] = i, 
				nx[i][j] = i;
	}
	for(int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int fl = 0;
		for(int j = 0; j < s; j++)
			if(a[r] & (1 << j))
				if(nx[l][j] <= r) fl = 1;
		if(fl == 1) cout<<"Shi"<<endl;
		else cout<<"Fou"<<endl;
	}
	return 0;
}