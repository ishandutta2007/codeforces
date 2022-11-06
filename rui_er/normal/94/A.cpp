//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

string s;
string a[11], b[11];

int main()
{
	cin>>s;
	for(int i=0;i<8;i++) a[i] = s.substr(i*10, 10);
	for(int i=0;i<10;i++) cin>>b[i];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(a[i] == b[j])
				cout<<j;
	cout<<endl;
	return 0;
}