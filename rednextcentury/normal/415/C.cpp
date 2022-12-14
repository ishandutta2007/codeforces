# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <cmath>
# include <iomanip>
# include <queue>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
long long c[1000000];
int main()
{
	int n,k;
	cin>>n>>k;
	if (n/2>k || (n==1 && k>0))
		cout<<-1<<endl;
	else
	{
		int turns=n/2;
		
			int y=turns-1;
			int j=k-y;
			c[0]=j;
			c[1]=j*2;
			if (n==3)
				c[2]=j*2+1;
			int val=j*2+2;
			for (int x=3;x<n;x++,val++)
			{
				
				c[x]=val;
				c[x-1]=val-1;
			}
		for (int i=0;i<n;i++)
		{
			cout<<c[i]<<" ";
		}
		
			cout<<endl;
	}
}