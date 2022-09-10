#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for (int I=0; I<t; I++)
	{
		int n, r, a, s=0;
		cin>>n;
		cin>>r;
		for (int i=1; i<n; i++)
		{
			cin>>a;
			s+=a;
		}
		int w=n;
		int mk=r-1;
		s%=n;
		w=mk-s;
		while (w<=0) w+=n;
		cout<<w<<"\n";
	}
	return 0;
}