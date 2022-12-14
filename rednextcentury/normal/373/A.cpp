# include <iostream>
# include <string>
# include <algorithm>
# include <iomanip>
# include <cmath>
# include <map>
using namespace std;
char a[4][4];
map<char,int> b;
int main()
{
	bool p=0;
	int k;
	cin>>k;
	for (int i=0;i<4;i++)
	{
		for (int x=0;x<4;x++)
		{
			cin>>a[i][x];
			b[a[i][x]]++;
			if (b[a[i][x]]>k*2 && a[i][x]!='.')
				p=1;
		}
	}
	if (p==1)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}