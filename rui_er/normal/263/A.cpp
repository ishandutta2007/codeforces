#include <bits/stdc++.h>
using namespace std;

int main()
{
	bool k;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>k;
			if(k)
			{
				cout<<abs(3-i)+abs(3-j)<<endl;
				return 0;
			}
		}
	}
	return 0;
}