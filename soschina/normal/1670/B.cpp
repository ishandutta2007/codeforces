#include <bits/stdc++.h>
using namespace std;

int t,n;
char s[200005];
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		scanf("%s",&s);
		char h;	 
		int k,cnt=1,ans=0;
		scanf("%d",&k);
		bool b[300]={0};
		for(int j=1;j<=k;j++) 
		{
			scanf(" %c",&h);
			//cout<<h<<endl;
			b[h]=1;
		}
		for(int j=1;j<=n;j++)
		{
			if(b[s[j-1]]==1)
			{
				//cout<<"knkn"<<endl;
				ans=max(ans,j-cnt);
				cnt=j;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}