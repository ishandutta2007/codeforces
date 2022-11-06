#include <iostream>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int l = s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y');
		else cout<<"."<<s[i];
	}
	cout<<endl;
	return 0;
}