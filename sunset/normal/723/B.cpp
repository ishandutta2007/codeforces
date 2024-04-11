#include<bits/stdc++.h>

using namespace std;

string s;

int maxx,cnt;

int main()
{
	int n;
	cin>>n;
	cin>>s;
	int len=s.length();
	bool flag=false;
	int tmp=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(')
		{
			flag=true;
			if(tmp)
				maxx=max(maxx,tmp),tmp=0;
		}
		else if(s[i]==')')
		{
			flag=false;
			if(tmp) cnt++,tmp=0;
		}
		else if(s[i]=='_')
		{
			if(flag)
			{
				if(tmp)
					cnt++,tmp=0;
			}
			else
				if(tmp)
					maxx=max(maxx,tmp),tmp=0;
		}
		else
		{
			tmp++;
		}
	}
	if(tmp)
		maxx=max(maxx,tmp);
	cout<<maxx<<" "<<cnt<<endl;
	return 0;
}