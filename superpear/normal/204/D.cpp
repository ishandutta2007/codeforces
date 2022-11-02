#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

const int bigp=1000000007;
const int maxn=1000005;

string s;
int n,k,e,ans,a[maxn],sum[maxn],bsum[maxn],wsum[maxn],t[maxn];
int b1[maxn],w1[maxn],sum1[maxn],b2[maxn],w2[maxn],sum2[maxn],cb[maxn],cw[maxn];

int mpow(int a,int b)
{
	if (b==0) return 1;
	int c=mpow(a,b/2);
	c=(long long)c*c%bigp;
	if (b%2==1) c=(long long)c*a%bigp;
	return c;
}

int main()
{
	//freopen("D.in","r",stdin);
	cin>>n>>k;
	cin>>s;
	memset(a,0,sizeof(a));
	memset(sum,0,sizeof(sum));
	memset(bsum,0,sizeof(bsum));
	memset(wsum,0,sizeof(wsum));
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='X') a[i]=0; else
		if (s[i-1]=='B') a[i]=1; else
		a[i]=2;
	}
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1];if (a[i]==0) ++sum[i];
		bsum[i]=bsum[i-1];if (a[i]==1) ++bsum[i];
		wsum[i]=wsum[i-1];if (a[i]==2) ++wsum[i];	
	}
	cw[0]=-1;
	for (int i=1;i<=n;i++)
	{
		cw[i]=cw[i-1];
		if (a[i]==2) cw[i]=i;
	}
	memset(b1,0,sizeof(b1));
	memset(w1,0,sizeof(w1));
	b1[0]=0;
	w1[0]=1;
	sum1[0]=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==1)
		{
			b1[i]=sum1[i-1];
			int e2=max(max(i-k+1,0),cw[i]);
			if (e2>0) b1[i]=(b1[i]-sum1[e2-1]+bigp)%bigp;
			//for (int j=i-1;j>=max(i-k+1,0);j--) b1[i]=(b1[i]+w1[j])%bigp;
			w1[i]=0;
		}
		else
			if (a[i]==2)
			{
				b1[i]=0;w1[i]=(b1[i-1]+w1[i-1])%bigp;
				if (k==1) w1[i]=w1[i-1];
			}
			else
			{
				w1[i]=(b1[i-1]+w1[i-1])%bigp;
				if (k==1) w1[i]=w1[i-1];
				b1[i]=sum1[i-1];
				int e2=max(max(i-k+1,0),cw[i]);
				if (e2>0) b1[i]=(b1[i]-sum1[e2-1]+bigp)%bigp;
			}
		sum1[i]=(sum1[i-1]+w1[i])%bigp;
	}
	//for (int i=1;i<=n;i++) cout<<w1[i]<<endl;
	for (int i=1;i<=n/2;i++) swap(a[i],a[n+1-i]);
	cb[0]=-1;
	for (int i=1;i<=n;i++)
	{
		cb[i]=cb[i-1];
		if (a[i]==1) cb[i]=i;
	}	
	memset(b2,0,sizeof(b2));
	memset(w2,0,sizeof(w2));
	b2[0]=1;
	w2[0]=0;
	sum2[0]=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==2)
		{
			w2[i]=sum2[i-1];
			int e2=max(max(i-k+1,0),cb[i]);
			if (e2>0) w2[i]=(w2[i]-sum2[e2-1]+bigp)%bigp;
			b2[i]=0;
		}
		else
			if (a[i]==1)
			{
				w2[i]=0;b2[i]=(b2[i-1]+w2[i-1])%bigp;
				if (k==1) b2[i]=b2[i-1];
			}
			else
			{
				b2[i]=(b2[i-1]+w2[i-1])%bigp;
				if (k==1) b2[i]=b2[i-1];
				w2[i]=sum2[i-1];
				int e2=max(max(i-k+1,0),cb[i]);
				if (e2>0) w2[i]=(w2[i]-sum2[e2-1]+bigp)%bigp;
			}
		sum2[i]=(sum2[i-1]+b2[i])%bigp;
	}
	//for (int i=1;i<=n;i++) cout<<b2[i]<<" "<<w2[i]<<endl;
	for (int i=1;i<=n/2;i++) swap(a[i],a[n+1-i]);
	memset(t,0,sizeof(t));
	for (int i=n-k+1;i>=1;i--)
	{
		if (a[i]==0) t[i]=t[i+1]*2%bigp; else t[i]=t[i+1];
		if (bsum[i+k-1]-bsum[i-1]==0) t[i]=(t[i]+b2[n+1-i-k])%bigp;
		//cout<<i<<" "<<t[i]<<endl;
	}
	ans=0;
	for (int i=k;i<=n;i++)
		if (wsum[i]-wsum[i-k]==0)
			ans=((long long)ans+(long long)w1[i-k]*t[i+1])%bigp;
	cout<<ans<<endl;
	
	return 0;
}