#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=800005;
char s[maxn],t[maxn];
int i,cnt1,cnt2,p1,p2;
bool t1[maxn],t2[maxn];
int c1[maxn],c2[maxn];
int opx[maxn],opy[maxn],opt;
int sz1,sz2,z,q,x,y,f;
bool sw;
void o(int x,int y)
{
	opt++;
	opx[opt]=x;
	opy[opt]=y;
}
int verdict(int x,int y,int z)
{
	int ret=0;
	if (z)
	{
		if (x>y)
			x--;
		else
			y--;
		ret++;
	}
	ret+=max(x,y)-1;
	return ret;
}
int main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	cnt1=cnt2=100001;
	for (i=1;s[i];i++)
	{
		if (s[i]!=s[i-1])
		{
			cnt1++;
			t1[cnt1]=s[i]-'a';
		}
		c1[cnt1]++;
	}
	for (i=1;t[i];i++)
	{
		if (t[i]!=t[i-1])
		{
			cnt2++;
			t2[cnt2]=t[i]-'a';
		}
		c2[cnt2]++;
	}
	p1=p2=100002;
	sz1=cnt1-p1+1;
	sz2=cnt2-p2+1;
	if (sz2>sz1+1)
	{
		for (i=p2;i<=cnt2;i++)
		{
			t1[i]^=t2[i]^=t1[i]^=t2[i];
			c1[i]^=c2[i]^=c1[i]^=c2[i];
		}
		sz1^=sz2^=sz1^=sz2;
		cnt1^=cnt2^=cnt1^=cnt2;
		sw=1;
	}
	if (sz1>sz2+1)
	{
		z=maxn;
		for (i=p1-1;i<=cnt1;i++)
		{
			if (verdict(cnt1-i+(t1[i+1]!=t2[p2]),
				sz2-1+i-p1+1-(t1[i]==t2[p2+1]),
				t1[p1]==t2[p2])<z)
			{
				z=verdict(cnt1-i+(t1[i+1]!=t2[p2]),
				sz2-1+i-p1+1-(t1[i]==t2[p2+1]),
				t1[p1]==t2[p2]);
				q=i;
				f=1;
			}
			if (verdict(cnt1-i,
				sz2+i-p1+1-(t1[i]==t2[p2]),
				t1[p1]==t1[i+1])<z)
			{
				z=verdict(cnt1-i,
				sz2+i-p1+1-(t1[i]==t2[p2]),
				t1[p1]==t1[i+1]);
				q=i;
				f=0;
			}
		}
		if (q)
		{
			z=0;
			for (i=p1;i<=q;i++)
				z+=c1[i];
			if (f)
				o(z,c2[p2]);
			else
				o(z,0);
			if (f)
			{
				x=t2[p2];
				y=c2[p2];
				p2++;
			}
			z=q;
			if (t1[q]==t2[p2])
			{
				c2[p2]+=c1[q];
				if (p2>cnt2)
					cnt2=p2;
				q--;
			}
			for (i=q;i>=p1;i--)
			{
				p2--;
				t2[p2]=t1[i];
				c2[p2]=c1[i];
			}
			p1=z+1;
			if (f)
			{
				if (t1[p1]==x)
					c1[p1]+=y;
				else
				{
					p1--;
					t1[p1]=x;
					c1[p1]=y;
				}
			}
		}
	}
	while (cnt1!=p1||cnt2!=p2)
	{
		if (t1[p1]!=t2[p2])
		{
			o(c1[p1],c2[p2]);
			c1[p1+1]+=c2[p2];
			c2[p2+1]+=c1[p1];
			p1++;
			p2++;
			if (p1>cnt1)
			{
				cnt1=p1;
				t1[cnt1]=t1[cnt1-1]^1;
			}
			if (p2>cnt2)
			{
				cnt2=p2;
				t2[cnt2]=t2[cnt2-1]^1;
			}
			continue;
		}
		if (cnt1-p1>cnt2-p2)
		{
			o(c1[p1],0);
			c2[p2]+=c1[p1];;
			p1++;
			if (p1>cnt1)
			{
				cnt1=p1;
				t1[cnt1]=t1[cnt1-1]^1;
			}
		}
		else
		{
			o(0,c2[p2]);
			c1[p1]+=c2[p2];
			p2++;
			if (p2>cnt2)
			{
				cnt2=p2;
				t2[cnt2]=t2[cnt2-1]^1;
			}
		}
	}
	printf("%d\n",opt);
	for (i=1;i<=opt;i++)
	{
		if (!sw)
			printf("%d %d\n",opx[i],opy[i]);
		else
			printf("%d %d\n",opy[i],opx[i]);
	}
	return 0;
}