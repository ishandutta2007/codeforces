#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
char buf[1000010];
int f[26];
struct atom
{
	int time;
	int type;//0:start,1:end
	char ch;
	inline bool operator<(const atom &x)const{return time==x.time?type<x.type:time<x.time;}
}arr[60];
int top;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",buf);
	for(int i=0;i<n;i++)
	{
		if(!f[buf[i]-'A'])
		{
			f[buf[i]-'A']=1;
			arr[++top].time=i;
			arr[top].type=0;
			arr[top].ch=buf[i];
		}
	}
	memset(f,0,sizeof(f));
	for(int i=n-1;i>=0;i--)
	{
		if(!f[buf[i]-'A'])
		{
			f[buf[i]-'A']=1;
			arr[++top].time=i;
			arr[top].type=1;
			arr[top].ch=buf[i];
		}
	}
	memset(f,0,sizeof(f));
	sort(arr+1,arr+top+1);
	int tmp=0,maxx=0;
	for(int i=1;i<=top;i++)
	{
		if(arr[i].type==0)
		{
			f[arr[i].ch-'A']=1;
			tmp++;
			if(tmp>maxx)maxx=tmp;
		}
		else
		{
			f[arr[i].ch-'A']=0;
			tmp--;
		}
	}
	if(maxx>m)printf("YES\n");
	else printf("NO\n");
	return 0;
}
/*

50 24
ABCDEFGHIJKLMNOPQRSTUVWXYABCDEFGHIJKLMNOPQRSTUVWXX

*/