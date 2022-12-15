#include <iostream>
#include <map>
# include <stdio.h>
# include <algorithm>
# include <string>
# include <queue>
# include <iomanip>
using namespace std;
int main()
{
	string s;
	int n,k;
	cin>>n>>k;
	if ((k>n)||(n>1 && k==1))
		cout<<-1<<endl;
	else if (n==1)
		cout<<"a\n";
	else
	{
		int v=0;
		for (int i=0;i<(n-k)+2;i++)
		{
			if (i%2==0)
				s+='a';
			else
				s+='b';
		}
		if ((n-k)+2>1)
			v=2;
		else
			v=1;
		for (int i=(n-k)+2;i<n;i++)
		{
			s+=char(int('a')+v);
			v++;
		}
		cout<<s<<endl;
	}
}