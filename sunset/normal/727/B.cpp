#include<bits/stdc++.h>

using namespace std;

double ans;

int q[100],cnt;

int main()
{
	string s;
	char qq[23];
	cin>>s;
	double tmp=0;
	double flag=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			ans+=tmp;
			tmp=0;
			flag=0;
		}
		else if(s[i]=='.')
		{
			if(i+2>=s.length()||(s[i+2]<'0'||s[i+2]>'9')||i+3>=s.length()||(s[i+3]<'0'||s[i+3]>'9'))
				flag=0.1;
		}
		else
		{
			if(flag)
			{
				tmp+=(s[i]-'0')*flag;
				flag*=0.1;
			}
			else
			{
				tmp=tmp*10+s[i]-'0';
			}
		}
	}
	if(tmp)
		ans+=tmp;
	bool f1=false;
	if(floor(ans)==ans) f1=true;
	//printf("%d %d\n",u,v);
	int ff=floor(ans);
	while(ff)
	{
		q[++cnt]=ff%10;
		ff/=10;
	}
	bool ffflag=false;
	for(int i=cnt;i;i--)
	{
		if(i%3==0&&ffflag)
			printf(".");
		printf("%d",q[i]);
		ffflag=true;
	}
	if(!cnt)
		printf("0");
	if(!f1)
	{
		printf(".");
		sprintf(qq,"%.2lf",ans-floor(ans));
		for(int i=2;i<=3;i++)
			cout<<qq[i];
	}
	return 0;
}