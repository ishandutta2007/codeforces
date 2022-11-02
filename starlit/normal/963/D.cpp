#include<bits/stdc++.h>
#define rep(x) for(j=1;j<=x;j++)
#define nrep for(j=n;j;j--)
#define N 100005
using namespace std;
int n,i,j,k,sa[N],rk[N<<1],h[N],v[N],t,m,l,st[N],tot;
char a[N],T[N];
int check(int x)
{
	//cout<<"check.."<<x<<endl;
	int ll=n-x+1;
	for(int i=0;i<l&&i<ll;i++)
	if(a[x+i]<T[i])return -1;
	else if(a[x+i]>T[i])return 2;
	if(l>ll)return -1;
	return 1;
}
int ll,rr,mid,tmp,t1,t2,ans;
int main()
{
	scanf("%s",a+1),n=strlen(a+1);
	rep(n)v[a[j]-='a'-1]=1;
	rep(26)v[j]+=v[j-1];
	t=v[26];
	rep(n)rk[j]=v[a[j]];
	for(i=1;i<=n&&t<n;i<<=1)
	{
		rep(n)h[rk[j+i]]++;
		rep(t)h[j]+=h[j-1];
		rep(n)sa[h[rk[j+i]]--]=j;
		rep(t)h[j]=0;
		rep(n)h[rk[j]]++;
		rep(t)h[j]+=h[j-1];
		nrep v[h[rk[sa[j]]]--]=sa[j];
		t=0;
		rep(n)h[v[j]]=(rk[v[j]]==rk[v[j-1]]&&rk[v[j]+i]==rk[v[j-1]+i])?t:++t;
		rep(n)rk[j]=h[j],h[j]=0;
	}
	rep(n)sa[rk[j]]=j;
	sa[t=0]=n+1;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%s",&k,T),l=strlen(T);t1=t2=n+1;
		for(i=0;i<l;i++)T[i]-='a'-1;
		for(ll=1,rr=n;ll<=rr;)
		{
			mid=ll+rr>>1;
			tmp=check(sa[mid]);//cout<<tmp<<endl;
			if(tmp<0)ll=mid+1;
			else t1=mid,rr=mid-1;
		}
		for(ll=1,rr=n;ll<=rr;)
		{
			mid=ll+rr>>1;
			tmp=check(sa[mid]);//cout<<tmp<<endl;
			if(tmp<2)ll=mid+1;
			else t2=mid,rr=mid-1;
		}
		tot=0;
		//cout<<t1<<" "<<t2<<endl;
		for(i=t1;i<t2;i++)
		st[tot++]=sa[i];
		sort(st,st+tot);ans=-1,k--;
		for(i=k;i<tot;i++)
		if(ans==-1||ans>st[i]-st[i-k])
		ans=st[i]-st[i-k];
		printf("%d\n",ans>=0?ans+l:-1);
	}
}