#include<bits/stdc++.h>
using namespace std;
char s[55],s2[55];
char t2[10]="abacaba";
int q[105];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,tt=0,tt2=0,ans=0,ans2=0,tot=0;
		cin>>n;
		scanf("%s",s+1);
		for(int i=1;i<=n-6;i++)
		{
			int flag=1;
			for(int j=i;j<=i+6;j++)
			{
				if(s[j]!='?'&&s[j]!=t2[j-i])
				{
					flag=0;
					break;
				}
				if(s[j]=='?')flag=2;
			}
			if(flag==1)
			{
				tt=i;
				ans++;
			}else if(flag==2)
			{
				ans2++;
				q[++tt2]=i;
			}
		}
		if(ans>=2||ans==0&&ans2==0)cout<<"No"<<endl;
		else if(ans)
		{
			cout<<"Yes"<<endl;
			for(int i=1;i<tt;i++)
			{
				if(s[i]=='?')printf("z");
				else printf("%c",s[i]);
			}
			cout<<t2;
			for(int i=tt+7;i<=n;i++)
			{
				if(s[i]=='?')printf("z");
				else printf("%c",s[i]);
			}
			cout<<endl;
		}else
		{
			int fio=0;
			for(int i=1;i<=tt2;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(j>=q[i]&&j<=q[i]+6)s2[j]=t2[j-q[i]];
					else
					{
						if(s[j]=='?')s2[j]='z';
						else s2[j]=s[j];
					}
				}
				int ans=0;
				for(int j=1;j+6<=n;j++)
				{
					int flag=1;
					for(int k=j;k<=j+6;k++)if(s2[k]!=t2[k-j])
					{
						flag=0;
						break;
					}
					ans+=flag;
				}
				if(ans==1)
				{
					fio=1;
					cout<<"Yes\n";
					for(int j=1;j<=n;j++)cout<<s2[j];
					cout<<endl;
					break;
				}
			}
			if(!fio)cout<<"No\n";
		}
	}
	return 0;
}