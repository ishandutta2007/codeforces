//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[4], ans = 0;
	for(int i=0;i<4;i++) cin>>a[i];
	for(int i=0;i<4;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			for(int k=j+1;k<4;k++)
			{
				int x, y, z;
				x = a[i];
				y = a[j];
				z = a[k];
				if(x + y > z && y + z > x && z + x > y) ans = 2;
				else if(x + y == z || y + z == x || z + x == y) ans = max(ans, 1); 
				else;
			}
		}
	}
	cout<<(ans==2?"TRIANGLE":(ans==1?"SEGMENT":"IMPOSSIBLE"))<<endl;
	return 0;
}