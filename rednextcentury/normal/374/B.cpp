# include <iostream>
# include <cmath>
# include <iomanip>
# include <algorithm>
# include <string>
using namespace std;
int main()
{
	unsigned long long ans=1;
	string s;
	cin>>s;
	int len=s.length();
	bool p=0;
	int now=0;
	for (int i=1;i<len;i++)
	{
		if (((int)s[i]-48)+(int(s[i-1]-48))==9 && p==0)
		{
			p=1;
		}
		if (((int)s[i]-48)+(int(s[i-1]-48))==9 && p==1)
		{
			now++;
		
		}
		if ((((int)s[i]-48)+(int(s[i-1]-48))!=9 && p==1)|| i==len-1)
		{
			p=0;
			if (now%2==0)
				ans*=now/2+1;
			now=0;
		}
	}
	cout<<ans<<endl;
}