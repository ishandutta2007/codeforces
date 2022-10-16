#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[51][51];
string s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=1;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int l=0;l<s.size();l++)
				a[i][l+1]=s[l]-'0';
		} 
		for(int i=1;i<n;i++)
			for(int l=1;l<n;l++)
				if(a[i][l])
					if(!a[i+1][l]&&!a[i][l+1])
						ans=0;
		if(ans)
			puts("YES");
		else
			puts("NO");
	} 
	return 0;
}