#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int len = s.size();
	bool flag = true;
	for(int i=1;i<len;i++) if(not(s[i] >= 'A' && s[i] <= 'Z')) flag = false;
	if(flag)
		for(int i=0;i<len;i++)
		{
			if(s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
			else if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
		}
	cout<<s<<endl;
	return 0;
}