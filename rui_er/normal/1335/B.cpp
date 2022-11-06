//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll T;
	ll n, a, b;
	cin>>T;
	while(T--)
	{
		cin>>n>>a>>b;
		for(int i=1;i<=n;i++) cout<<(char)('a'+(i-1)%b);
		cout<<endl;
	}
	return 0;
}