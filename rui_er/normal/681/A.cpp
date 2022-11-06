#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		int before, after;
		cin>>s>>before>>after;
		if(after > before && before >= 2400)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}