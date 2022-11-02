#include<cstdio>
#include<iostream>
#include<cstring>
#define N 100005
using namespace std;
int n,mn[N],lst[N];
int q[N],tot=1,now;
bool inq[N]={1};
int mp[500],cnt;
int main()
{
	scanf("%d",&n);
	if(!n){puts("a");return 0;}
	memset(mn,0x3f,sizeof mn);
	mn[0]=0;
	for(cnt=1;(cnt*(cnt-1)>>1)<=n;cnt++)
	mp[cnt]=(cnt*(cnt-1)>>1);
	for(int i=cnt;i>1&&!inq[n];i--)
	{
		for(int j=0;j<tot&&!inq[n];j++)
		if(q[j]+mp[i]<=n&&mn[q[j]+mp[i]]>mn[q[j]]+1)
		{
			mn[q[j]+mp[i]]=mn[q[j]]+1,lst[q[j]+mp[i]]=i;
			if(mn[q[j]+mp[i]]<26&&!inq[q[j]+mp[i]])
			inq[q[tot++]=q[j]+mp[i]]=1;
		}
	}
	for(int i=n;i;i=i-mp[lst[i]])
	{
		for(int j=0;j<lst[i];j++)
		putchar(now+'a');
		now++;
	}
}