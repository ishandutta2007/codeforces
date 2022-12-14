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
	int draw=0,first=0,second=0;
	for (int i=1;i<=6;i++)
	{
		int x=abs(a-i);
		int y=abs(b-i);
		if (x==y)
			draw++;
		else if (x<y)
			first++;
		else
			second++;
	}
	cout<<first<<" "<<draw<<" "<<second<<endl;
}