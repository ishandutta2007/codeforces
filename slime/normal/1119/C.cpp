#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define maxn 3005
#define ll long long
#define ld double
#define mod 1000000007
using namespace std;
int n, m;
int a[maxn][maxn], b[maxn][maxn];
int x[maxn], y[maxn];
int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin>>a[i][j], 
			x[i] ^= a[i][j], 
			y[j] ^= a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin>>b[i][j], 
			x[i] ^= b[i][j], 
			y[j] ^= b[i][j];
	int fl = 1;
	for(int i = 1; i <= n; i++)
		if(x[i])
			fl = 0;
	for(int i = 1; i <= m; i++)
		if(y[i]) fl = 0;
	if(fl) cout<<"YES";
	else cout<<"NO";
	return 0;
}