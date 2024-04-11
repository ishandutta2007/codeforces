#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s[n];
	bool flag = false;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		if(s[i][0] == 'O' && s[i][1] == 'O' && !flag)
		{
			s[i][0] = '+';
			s[i][1] = '+';
			flag = true;
		}
		if(s[i][3] == 'O' && s[i][4] == 'O' && !flag)
		{
			s[i][3] = '+';
			s[i][4] = '+';
			flag = true;
		}
	}
	if(!flag)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++) cout<<s[i]<<endl;
	return 0;
}///////////////////////////////////////