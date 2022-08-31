#include <bits/stdc++.h>
#define maxn 300005
#define ll long long
using namespace std;
int n, k;
char inp[maxn];
int f[2][2]; 
int main()
{
	for(int i = 0; i < 2; i++)
		f[i][0] = maxn, f[i][1] = 0;
	cin>>n>>k;
	scanf("%s", inp + 1);
	for(int i = 1; i <= n; i++)
	{
		int u = inp[i] - '0';
		f[u][0] = min(f[u][0], i), 
		f[u][1] = max(f[u][1], i);
	}
	for(int i = 0; i < 2; i++)
		if(f[i][1] - f[i][0] + 1 <= k)
		{
			cout<<"tokitsukaze"<<endl;
			return 0;
		}
	int fl = 1;
	for(int i = 0; i < 2; i++)
	{
		if(f[i][1] - f[i][0] + 1 != k + 1) fl = 0;
		if(f[i][0] >= k + 1) fl = 0;
		if(f[i][1] + k <= n) fl = 0;
	}
	if(fl)
		cout<<"quailty"<<endl;
	else cout<<"once again"<<endl;
	return 0;
}