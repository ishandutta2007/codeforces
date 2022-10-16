#include<bits/stdc++.h>
using namespace std;
char s[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int len,ok=0;
		cin>>len;
		cin>>(s+1);
		for(int i=1;i<=len;i++)
		{
			if(s[i]!='?')
			{
				for(int j=i-1;j>=1;j--)
				{
					if(s[j]=='?')s[j]='R'+'B'-s[j+1];
				}
				for(int j=i+1;j<=len;j++)
				{
					if(s[j]=='?')s[j]='R'+'B'-s[j-1];
				}
				ok=1;
				break;
			}
		}
		if(!ok)
		{
			for(int i=1;i<=len;i++)
			{
				s[i]="RB"[i%2];
			}
		}
		cout<<(s+1)<<endl;
	}
	return 0;
}