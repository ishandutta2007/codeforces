// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

char s[1000111];
int n,sum[1000111],a[1000111],m,tot,b[1000111],id[1000111],pre[1000111],nxt[1000111];
bool use[1000111];
int stk[1000111],top,vl[1000111];
bool check(int x)
{
	int cvr=0;top=0;
	memset(use,0,sizeof(use));
	for(int i=1;i<=m;i++)
	{
		if(b[cvr+1]>=a[i])cvr=max(cvr,pre[min(n,a[i]+x)]);
		else
		{
			int tl=nxt[max(1,a[i]-x)];
			if(tl==0||tl>cvr+1)return false;
			int tcvr=cvr+1;
			cvr=max(cvr,pre[a[i]]);
			if(use[i-1]){
				if(vl[i-1]>=tl)
				{
					cvr=max(cvr,pre[min(n,a[i-1]+x)]);
					tcvr=vl[i-1];use[i-1]=0;
				}
				else if(i>2&&!use[i-2]){
//					puts("isok");
					if(nxt[a[i-2]]>=tl){
						use[i-2]=1;use[i-1]=0;
						cvr=max(cvr,pre[min(n,a[i-1]+x)]);
						tcvr=nxt[a[i-2]];
					}
				}
			}
			use[i]=1;vl[i]=tcvr;
		}
//		printf("%d %d\n",i,cvr);
		if(cvr==tot)return true;
	}
	return false;
}
int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(s[i]=='*');
	for(int i=1;i<=n;i++)if(s[i]=='P')a[++m]=i;else if(s[i]=='*'){id[i]=++tot;b[tot]=i;}
	for(int i=1;i<=n;i++)if(s[i]=='*')pre[i]=id[i];else pre[i]=pre[i-1];
	for(int i=n;i>=1;i--)if(s[i]=='*')nxt[i]=id[i];else nxt[i]=nxt[i+1];
	if(m==1)
	{
		int l=0,r=0;
		for(int i=1;i<=n;i++)if(s[i]=='*')
		{
			if(l==0)l=i;
			r=i;
		}
		if(sum[n]-sum[a[1]]>sum[a[1]])printf("%d %d\n",sum[n]-sum[a[1]],r-a[1]);
		else if(sum[n]-sum[a[1]]<sum[a[1]])printf("%d %d\n",sum[a[1]],a[1]-l);
		else printf("%d %d\n",sum[a[1]],min(r-a[1],a[1]-l));
	}
	else
	{
		printf("%d ",sum[n]);
		int l=0,r=n,mid;
		while(l<r-1)
		{
			mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid;
		}
//		printf("check(33)=%d ",check(33));
		printf("%d\n",r);
	}
	return 0;
}