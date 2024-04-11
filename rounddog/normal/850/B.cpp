#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#define maxn 2000050

using namespace std;
typedef long long ll;

ll ans,x,y,sum[maxn],n,s,t,d,cnt[maxn],c[maxn],p,q;
bool f[maxn];

int main()
{
	scanf("%d%d%d",&n,&x,&y);
	ans=min(x,y)*n;
	d=x/y;
	memset(c,0,sizeof(c));
	memset(f,true,sizeof(f));
	for (int i=2;i<maxn;i++)
	    if (f[i]) for (int j=2;i*j<maxn;j++) f[i*j]=false; 
	for (int i=0;i<n;i++) 
	{
		scanf("%d",&t);
		//a[i]=3+rand()%1000000;
		c[t]++;
	}
	cnt[0]=0;sum[0]=0;
	for (int i=1;i<maxn;i++) cnt[i]=cnt[i-1]+c[i];
	for (int i=1;i<maxn;i++) sum[i]=sum[i-1]+c[i]*i;
	for (int i=2;i<maxn;i++)
	    if (f[i]){
	    	s=0;t=min(d+1,(ll)i);p=0;
	    	//if (i==17) printf("%d\n",t);
	    	for (int j=1;i*j<maxn;j++)
	    	{
	    		q=cnt[i*j]-cnt[i*j-t];
	    		p+=q;
	    		s+=q*i*j-(sum[i*j]-sum[i*j-t]);
	    		//if (i==17&&j==1) printf("%d\n",s);
	    	}
	    	s=s*y;
	    	s+=(n-p)*x;
	    	ans=min(s,ans);
	    }
	printf("%I64d\n",ans);
	return 0;
}