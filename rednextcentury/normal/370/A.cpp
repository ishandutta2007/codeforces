# include <iostream>
# include <string>
# include <algorithm>
# include <iomanip>
# include <cmath>
using namespace std;
int a[8][8];
int main()
{
	for (int i=0;i<8;i++)
	{
		if (i%2==0)
			a[0][i]=1;
		else
			a[0][i]=0;
	}
	for (int i=1;i<8;i++)
	{
		for (int x=0;x<8;x++)
		{
			if (a[i-1][x]==1)
				a[i][x]=0;
			else
				a[i][x]=1;
		}
	}
	int r1,c1,r2,c2;
	cin>>r1>>c1>>r2>>c2;
	int rook,bishop,king; 
	if (r1==r2 || c1==c2)
		rook=1;
	else
		rook=2;
	if (abs(r1-r2)==abs(c1-c2))
		bishop=1;
	else
		bishop=2;
	king=min(abs(r1-r2),abs(c1-c2));
	king+=abs(abs(r1-r2)-abs(c1-c2));
		if (a[r1-1][c1-1]!=a[r2-1][c2-1])
			bishop=0;
	cout<<rook<<" "<<bishop<<" "<<king<<endl;
}