# include <iostream>
# include <string>
# include <map>
# include <cmath>
# include <queue>
using namespace std;
int a[1000];
int main()
{
	int n,c;
	cin>>n>>c;
	int max=-1000000;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		if (i>0)
			if (a[i-1]-a[i]>max)
				max=a[i-1]-a[i];
	}
	if (max-c>0)
		cout<<max-c<<endl;
	else
		cout<<0<<endl;
}