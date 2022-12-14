#include <iostream>
#include <map>
# include <string>
using namespace std;
map<char,int> a;
int main()
{
	string s;
	cin>>s;
	int odd=0;
	for (int i=0;i<s.length();i++)
	{
		a[s[i]]++;
		if (a[s[i]]%2!=0)
			odd++;
		else
			odd--;
	}
	if (odd%2!=0 || odd==0)
		cout<<"First"<<endl;
	else
		cout<<"Second"<<endl;
}