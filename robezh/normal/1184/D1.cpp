#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 250;
int n,k,m,t;
int a[maxn+1];


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> k >> m >> t;
	a[k] = 1;
	for (int i=1; i<=t; i++)
	{
		int op,pos;
		cin >> op >> pos;
		if (op==1)
		{
			for (int j=n+1; j>pos; j--)
				a[j] = a[j-1];
			a[pos]=0;
			n++;
			cout << n << ' ';
			for (int j=1; j<=n; j++)
				if (a[j]==1)
					cout << j << '\n';
		}
		else
		{
			bool flag = false;
			for (int j=1; j<=pos; j++)
				if (a[j]==1)
					flag = true;
			
			if (flag)
				n=pos;
			else
			{
				for (int j=1; j<=n-pos; j++)
					a[j] = a[j+pos];
				n-=pos;
			}
			cout << n << ' ';
			for (int j=1; j<=n; j++)
				if (a[j]==1)
					cout << j << '\n';
		}
	}
	
	return 0;
}