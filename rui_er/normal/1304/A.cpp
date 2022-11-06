//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T;
int x, y, a, b, i;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>x>>y>>a>>b;
		int k = x;
		x = 0;
		y -= k;
		if(y % (a + b) == 0) cout<<y/(a+b)<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}