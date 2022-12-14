# include <iostream>
# include <algorithm>
# include <string>
# include <map>
using namespace std;
int main()
{
	int n,bowl,plate;
	cin>>n>>bowl>>plate;
	int one,two;
	one=0;two=0;
	for (int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		if (a==1)
			one++;
		else
			two++;
	}
	if (two<plate)
		two=0;
	else
		two=two-plate;
	bowl-=one;
	if (bowl>0)
	{
		bowl-=two;
		cout<<max(-bowl,0)<<endl;
	}
	else
		cout<<(-bowl)+two<<endl;
}