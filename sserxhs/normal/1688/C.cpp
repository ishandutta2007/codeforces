//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n;
		char c=0;
		cin>>n;
		n=n*2+1;
		while (n--)
		{
			string s;
			cin>>s;
			for (auto x:s) c^=x;
		}
		cout<<c<<'\n';
	}
}