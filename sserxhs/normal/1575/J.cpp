#include <bits/stdc++.h>
using namespace std;
const int N=1e3+2;
int a[N][N];
int n,i,j,x,y,m,q;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q;
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) cin>>a[i][j];
	while (q--)
	{
		cin>>y;x=1;
		while (x<=n)
		{
			if (a[x][y]==2) ++x; else
			{
				if (a[x][y]==1) a[x][y++]=2; else a[x][y--]=2;
			}
		}
		cout<<y<<' ';
	}
}