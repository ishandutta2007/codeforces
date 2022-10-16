#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int MAXN=100010;
int n,k;
int vis[MAXN],ok[MAXN],t[MAXN];
string nam[MAXN],qwq="qwq";
char out[MAXN][25];
int sti(string str)
{
	if(str[0]=='0')return -1;
	int ret=0;
	for(int i=0;i<str.length();i++)
	{
		if(!isdigit(str[i]))return -1;
		ret=ret*10+str[i]-'0';
		if(ret>n)return -1;
	}
	return ret;
}
string its(int x)
{
	string ret="";
	while(x)
	{
		ret=char(x%10+'0')+ret;
		x/=10;
	}
	return ret;
}
char buf[11];
queue<int> q[2],qq[2],e[2];
int cnt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf(" %s %d",buf,&t[i]);
		nam[i]=buf;
		k+=t[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x=sti(nam[i]);
		if(x!=-1)
		{
			if((t[i]==1&&x<=k)||(t[i]==0&&x>k))
			{
				vis[x]=1;
				ok[i]=1;
			}
			else
			{
				vis[x]=2;
				ok[i]=2;
				q[t[i]].push(i);
			}
		}
		else
		{
			qq[t[i]].push(i);
		}
	}
	for(int i=1;i<=k;i++)if(!vis[i])e[0].push(i);
	for(int i=k+1;i<=n;i++)if(!vis[i])e[1].push(i);
	if(e[0].empty()&&e[1].empty()&&!q[0].empty())
	{
		sprintf(out[++cnt],"move %s %s\n",nam[q[0].front()].c_str(),qwq.c_str());
		e[0].push(sti(nam[q[0].front()].c_str()));
		nam[q[0].front()]=qwq;
		qq[0].push(q[0].front());
		q[0].pop();
	}
	while(!e[0].empty()||!e[1].empty())
	{
		if(!e[0].empty()&&!q[1].empty())
		{
			int c=e[0].front();e[0].pop();
			sprintf(out[++cnt],"move %s %s\n",nam[q[1].front()].c_str(),its(c).c_str());
			vis[c]=1;
			e[1].push(sti(nam[q[1].front()]));
			qq[1].push(q[1].front());
			q[1].pop();
		}
		else if(!e[1].empty()&&!q[0].empty())
		{
			int c=e[1].front();e[1].pop();
			sprintf(out[++cnt],"move %s %s\n",nam[q[0].front()].c_str(),its(c).c_str());
			vis[c]=1;
			e[0].push(sti(nam[q[0].front()]));
			qq[0].push(q[0].front());
			q[0].pop();
		}
		else if(!e[0].empty()&&!qq[1].empty())
		{
			int c=e[0].front();e[0].pop();
			sprintf(out[++cnt],"move %s %s\n",nam[qq[1].front()].c_str(),its(c).c_str());
			vis[c]=1;
			qq[1].pop();
		}
		else if(!e[1].empty()&&!qq[0].empty())
		{
			int c=e[1].front();e[1].pop();
			sprintf(out[++cnt],"move %s %s\n",nam[qq[0].front()].c_str(),its(c).c_str());
			vis[c]=1;
			qq[0].pop();
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%s",out[i]);
	return 0;
}