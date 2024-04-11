#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define mod 1000000007
using namespace std;
int n, m;
int p[maxn], q[maxn];
int nx[maxn];
int nt[maxn][20];
int pl[maxn];
int f[maxn];
int mn[maxn][20];
int mt[maxn];
char otp[maxn];
int main()
{
	int n, m, Q;
	cin>>n>>m>>Q;
	for(int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for(int i = 1; i < n; i++)
		nx[p[i]] = p[i + 1], 
		pl[i] = m + 1;
	pl[n] = m + 1;
	nx[p[n]] = p[1];
	for(int i = 1; i <= m; i++)
		scanf("%d", &q[i]);
	nt[m + 1][0] = m + 1;
	for(int i = m; i >= 1; i--)
	{
		nt[i][0] = pl[nx[q[i]]];
		pl[q[i]] = i;
	}
	for(int j = 1; j < 20; j++)
		for(int i = m + 1; i >= 1; i--)
		{
			if(i == m + 1)
				nt[i][j] = m + 1;
			else 
				nt[i][j] = nt[nt[i][j - 1]][j - 1];
		}
	//cout<<"AFT"<<endl;
	for(int i = 1; i <= m; i++)
	{
		int pl = i;
		for(int j = 0; j < 20; j++)
			if((n - 1) & (1 << j))
				pl = nt[pl][j];
		f[i] = pl;
	//	cout<<i<<" "<<f[i]<<endl;
	}
	for(int i = 0; i < 20; i++)
		for(int j = (1 << i); j < (1 << (i + 1)) && j < maxn; j++)
			mt[j] = i;
	for(int i = 0; i < 20; i++)
		for(int j = 1; j <= m; j++)
		{
			if(i == 0) mn[j][i] = f[j];
			else
			{
				mn[j][i] = mn[j][i - 1];
				if(j + (1 << (i - 1)) <= m)
					mn[j][i] = min(mn[j][i], mn[j + (1 << (i - 1))][i - 1]);
			}
		}
	for(int i = 0; i < Q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int ns = mt[r - l + 1];
		int nm = min(mn[l][ns], mn[r - (1 << ns) + 1][ns]);
		if(nm <= r) otp[i] = '1';
		else otp[i] = '0';
	} 
	cout<<otp<<endl;
	return 0;
}