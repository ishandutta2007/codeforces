#include<iostream>
#include<algorithm>
using namespace std;
string s[105];
int sn;
int main()
{
	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.size();++i)for(int j=0;j<b.size();++j)
	{
		++sn;
		for(int k=0;k<=i;++k)s[sn]+=a[k];
		for(int k=0;k<=j;++k)s[sn]+=b[k];
	}
	sort(s+1,s+sn+1);
	cout<<s[1];
}