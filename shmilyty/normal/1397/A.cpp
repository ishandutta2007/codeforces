#include<bits/stdc++.h>
using namespace std;
int t,n,num[26]; 
string s;
void judge()
{
	for(int i=0;i<26;i++)
		if(num[i]%n)
		{
			puts("NO");
			return ;	
		}	
	puts("YES");
	return ;
} 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int l=0;l<s.size();l++)
				num[s[l]-'a']++;
		}
		judge();
	}
	return 0;
}