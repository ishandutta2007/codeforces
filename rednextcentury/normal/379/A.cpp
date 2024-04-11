# include <iostream>
# include <string>
# include <map>
# include <cmath>
# include <algorithm>
# include <iomanip>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int hours=0;
	int old=0;
	while (true)
	{
		if (old==b)
		{
			old-=b;
			a++;
		}
		if (a>0)
		{
			hours++;
			a--;
old++;
		}
		else break;
	}
	cout<<hours<<endl;
}