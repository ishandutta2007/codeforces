# include <iostream>
# include <string>
# include <algorithm>
# include <ios>
# include <stdio.h>
using namespace std;
int a[30];
int main()
{
	char x;
	cin>>x;
	while(cin>>x)
	{
		if (x=='}')
		{
			break;
		}
		else if (x!=',')
			a[x-'a']=1;
	}
	int ans=0;
	for (int i=0;i<30;i++)
	{
		if (a[i]>0)
			ans++;
	}
	cout<<ans<<endl;
}