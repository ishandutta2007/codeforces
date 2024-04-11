//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n; 

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n&1) cout<<(n>>1)<<endl;
		else cout<<((n>>1)-1)<<endl;
	}
	return 0;
}