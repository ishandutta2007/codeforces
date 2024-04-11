#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int posx = 1000;
	int posy = 0;
	int x=1000;
	int y=0;
	for(int i = 0;i<n;i++)
	{
		char a[200];
		cin>>a;
		for(int j = 0;j<m;j++)
		{
			if(a[j]=='B') 
			{
				posx= min(posx,i);
				posy= max(posy,i);
				x=min(x,j);
				y=max(y,j);
			}
		}
	}
	int aa = (x+y)>>1;
	int bb = (posx+posy)>>1;
	printf("%d %d\n",bb+1,aa+1);
	return 0;
}