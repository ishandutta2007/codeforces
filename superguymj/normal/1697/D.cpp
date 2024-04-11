#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid ((l+r)>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=1005;
char s[N];
int n,lst[30],top,stk[30];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

char get(int x)
{
	printf("? 1 %d\n",x);
	fflush(stdout);
	char s[5];
	scanf("%s",s);
	return s[0];
}

int query(int l,int r)
{
	printf("? 2 %d %d\n",l,r);
	fflush(stdout);
	int rt;
	scanf("%d",&rt);
	return rt;
}

void init(int n)
{
	rep(i,1,n) lst[s[i]-'a']=i;
	top=0;
	rep(i,1,n) if(lst[s[i]-'a']==i) stk[++top]=i;
}

int main()
{
	scanf("%d",&n);
	s[1]=get(1);
	init(1);
	rep(i,2,n)
	{
		int l=1,r=top;
		while(l<=r)
		{
			if(query(stk[mid],i)==top-mid+1) l=mid+1;
			else r=mid-1;
		}
		--l;
		if(!l) s[i]=get(i);
		else s[i]=s[stk[l]];
		init(i);
	}
	printf("! ");
	rep(i,1,n) putchar(s[i]);
	puts("");
	fflush(stdout);
	return 0;
}