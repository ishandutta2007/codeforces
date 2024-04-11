#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=400005;
int n,pool[N],a[N],ans;
int t1[N],t2[N],t3[N],a1[N],a2[N],f1[N],f2[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int find(int x)
{
	int l=1,r=n+n;
	while(l<=r) pool[mid]<=x?l=mid+1:r=mid-1;
	return l-1;
}

void insert(int t[],int x,int y)
{
	for(int i=x; i<=n*2; i+=i&-i) t[i]=max(t[i],y);
}

int query(int t[],int x)
{
	int rt=0;
	for(int i=x; i; i-=i&-i) rt=max(rt,t[i]);
	return rt;
}

int main()
{
	n=getint();
	rep(i,1,n) pool[++*pool]=a[i]=getint()-i,pool[++*pool]=a[i]+1;
	sort(pool+1,pool+1+n+n);
	rep(i,1,n) a1[i]=find(a[i]),a2[i]=find(a[i]+1);
	rep(i,1,n)
	{
		f1[i]=query(t1,a1[i])+1;
		f2[i]=max(query(t3,a2[i]),query(t2,a2[i]))+1;
		ans=max(ans,max(f1[i],f2[i])),insert(t1,a1[i],f1[i]),insert(t2,a2[i],f2[i]);
		if(i!=1) insert(t3,a1[i-1],f1[i-1]);
	}
	printf("%d\n",max(0,n-ans-1));
	return 0;
}