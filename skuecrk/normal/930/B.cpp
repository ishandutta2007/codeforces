#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define MN 5000
char s[MN+5];
vector<int> v[26];
int u[26];
int main()
{
	int n,i,j,k,ss,mx,ans=0;
	scanf("%s",s);n=strlen(s);
	for(i=0;i<n;++i)v[s[i]-'a'].push_back(i);
	for(i=0;i<26;++i)
	{
		for(j=mx=0;j<n;++j)
		{
			for(k=ss=0;k<v[i].size();++k)
			{
				if(u[s[(v[i][k]+j)%n]-'a']==1)--ss;
				if(!u[s[(v[i][k]+j)%n]-'a']++)++ss;
			}
			mx=max(mx,ss);
			for(k=0;k<v[i].size();++k)--u[s[(v[i][k]+j)%n]-'a'];
		}
		ans+=mx;
	}
	printf("%.10lf",(double)ans/n);
}