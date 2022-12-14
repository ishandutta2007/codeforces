# include <iostream>
# include <string>
# include <map>
# include <cmath>
# include <algorithm>
# include <iomanip>
using namespace std;
int a[1000];
int main()
{
	string s;
	int n;
	int stop=0;
	cin>>n;
	for (int i=0;i<n;i++) 
	{
		cin>>a[i];
		stop+=a[i];
	}
	int i=0;
	char way='R';
	while (true)
	{
		if (a[i]>0)
		{
			cout<<"P";
			a[i]--;
			stop--;
		}
		if (stop==0)
			break;
		if (way=='R' && i+1<n)
		{
			cout<<"R";
			i++;
		}
		else if (way=='R')
		{
			way='L';
			cout<<"L";
			i--;
		}
		else if (way=='L' && i-1>=0)
		{
			cout<<"L";
			i--;
		}
		else
		{
			way='R';
			cout<<"R";
			i++;
		}
	}
	cout<<endl;
}