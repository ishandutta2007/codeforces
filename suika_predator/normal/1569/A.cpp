#include<bits/stdc++.h>
using namespace std;
char s[233];
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n>>(s+1);
		int ok=0;
		for(int l=1;l<=n and not ok;l++)
		{
			for(int r=l;r<=n and not ok;r++)
			{
				int c0=0,c1=0;
				for(int i=l;i<=r;i++)
				{
					if(s[i]=='a')c0++;
					else c1++;
				}
				if(c0==c1)
				{
					cout<<l<<' '<<r<<endl;
					ok=1;
				}
			}
		}
		if(not ok)cout<<-1<<' '<<-1<<endl;
	}
	
	return 0;
}