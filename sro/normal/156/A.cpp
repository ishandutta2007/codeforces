#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s1,s2;

int main()
{
	//freopen("tongyonginput.in","r",stdin);
	//freopen("tongyongoutput.out","w",stdout);
	int n,ans,i,j;
	cin>>s1>>s2;
	ans=n=s2.size();
	s1=string(n,'`')+s1+string(n,'`');
	for(int i=0;i+(int)s2.size()<=(int)s1.size();i++)
	{
		n=0;
		for(int j=0;j<(int)s2.size();j++)
			n+=s1[i+j]!=s2[j];
		if(ans>n)ans=n;
	}
	printf("%d\n",ans);
	return 0;
}