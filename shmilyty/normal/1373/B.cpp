#include<bits/stdc++.h>
using namespace std;
int t,num1,num0,minn;
string s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		num1=num0=0;
		for(int i=0;i<s.size();i++)
			if(s[i]=='1')
				num1++;
			else
				num0++;
		minn=min(num1,num0);
		if(minn%2)
			puts("DA");
		else
			puts("NET");
	}
	return 0;
}