//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		int l = s.length();
		int first, last;
		if(s.find('1') != string::npos)
		{
			first = s.find_first_of('1');
			last = s.find_last_of('1');
		}
		else
		{
			cout<<"0"<<endl;
			continue;
		}
		int cnt = 0;
		for(int i=first;i<=last;i++)
			if(s[i] == '0')
				++cnt;
		cout<<cnt<<endl;
	}
	return 0;
}