//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c, d, x, y, x1, y1, x2, y2; 

int main()
{
	cin>>T;
	while(T--)
	{
		a = b = c = d = x = y = x1 = y1 = x2 = y2 = 0;
		cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
		if(x1 == x2 && y1 == y2)
		{
			cout<<"No"<<endl;
			continue;
		}
		if(x1 == x2 && (a || b))
		{
			cout<<"No"<<endl;
			continue;
		}
		if(y1 == y2 && (c || d))
		{
			cout<<"No"<<endl;
			continue;
		}
		int tmp = min(a, b);
		a -= tmp;
		b -= tmp;
		tmp = min(c, d);
		c -= tmp;
		d -= tmp;
		if(x - x1 < a || x2 - x < b || y - y1 < c || y2 - y < d)
		{
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
	}
	return 0;
}