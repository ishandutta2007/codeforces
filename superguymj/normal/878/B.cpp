#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n,k,m,tot,a[N],ct[N];
int len1[N],len2[N],head,tail,L[N];
long long ans;

bool check()
{
	rep(i,1,tot-1) if(a[i]!=a[i+1]) return 0;
	return 1;
}

int get(int l1,int r1,int l2,int r2)
{
	int rt=0;
	memset(ct,0,sizeof(ct));
	for(int i=l1; i<=r2;)
	{
		++rt,L[rt]=a[i];
		if(L[rt]==L[rt-1]) ct[rt]=ct[rt-1]+1;
		else ct[rt]=1;
		if(ct[rt]==k) rt-=k;
		++i;
		if(i>r1 && i<l2) i=l2;
	}
	return rt;
}

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	rep(i,1,n)
	{
		++tot,scanf("%d",&a[tot]);
		if(a[tot]==a[tot-1]) ct[tot]=ct[tot-1]+1;
		else ct[tot]=1;
		if(ct[tot]==k) tot-=k;
	}
	if(check())
	{
		printf("%I64d\n",(long long)n*m%k);
		return 0;
	}
	for(int i=1,j; i<=tot; i=j+1)
	{
		for(j=i; j+1<=tot && a[j]==a[j+1]; ++j);
		len1[i]=j-i+1;
	}
	for(int i=tot,j; i>=1; i=j-1)
	{
		for(j=i; j-1>=1 && a[j]==a[j-1]; --j);
		len2[i]=i-j+1;
	}
	ans=(long long)m*tot,head=1,tail=tot;
	while(ans)
	{
		if(a[head]!=a[tail]) break;
		if(len1[head]+head-1==tail)
		{
			if((long long)len1[head]*m%k==0) {ans=get(1,head-1,tail+1,tot); break;}
			else {ans=(long long)len1[head]*m%k+head-1+tot-tail; break;}
		}
		if((len1[head]+len2[tail])%k)
		{
			ans-=((long long)len1[head]+len2[tail]-(len1[head]+len2[tail])%k)*(m-1);
			break;
		}
		else
		{
			ans-=((long long)len1[head]+len2[tail])*(m-1);
			head=head+len1[head];
			tail=tail-len2[tail];
		}
	}
	printf("%I64d\n",ans);
	return 0;
}