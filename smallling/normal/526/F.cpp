#include<cstdio>
#include<algorithm>

using namespace std;

int x,y,nowx,n,a[300030],Max[300030],Min[300030],sum[300030];
long long ans;

void Work(int l,int r)
{
	if(l>r)return;
	int mid=(l+r)>>1;
	Max[mid]=Min[mid]=a[mid];
	Max[mid+1]=Min[mid+1]=a[mid+1];
	for(int i=mid+2;i<=r;i++)Max[i]=max(Max[i-1],a[i]),Min[i]=min(Min[i-1],a[i]);
	for(int i=mid-1;i>=l;i--)Max[i]=max(Max[i+1],a[i]),Min[i]=min(Min[i+1],a[i]);
	for(int i=mid+1;i<=r;i++)
	{
		nowx=i-Max[i]+Min[i];
		if(nowx>=l&&nowx<=mid&&Max[nowx]<=Max[i]&&Min[nowx]>=Min[i])ans++;
	}
	for(int i=mid;i>=l;i--)
	{
		nowx=i+Max[i]-Min[i];
		if(nowx<=r&&nowx>=mid&&Max[nowx]<=Max[i]&&Min[nowx]>=Min[i])ans++;
	}
	int L=mid+1,R=mid+1;
	for(int i=mid;i>=l;i--)
	{
		while(R<=r&&Min[R]>=Min[i])sum[Max[R]-R+mid]++,R++;
		while(L< R&&Max[L]<=Max[i])sum[Max[L]-L+mid]--,L++;
		ans+=sum[Min[i]-i+mid];
	}
	for(int i=L;i<R;i++)sum[Max[i]-i+mid]--;
	L=mid,R=mid;
	for(int i=mid+1;i<=r;i++)
	{
		while(R>=l&&Min[R]>=Min[i])sum[Max[R]+R-mid]++,R--;
		while(L> R&&Max[L]<=Max[i])sum[Max[L]+L-mid]--,L--;
		ans+=sum[Min[i]+i-mid];
	}
	for(int i=L;i>R;i--)sum[Max[i]+i-mid]--;
	Work(l,mid-1);
	Work(mid+1,r);
}

inline void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		read(x);read(y);
		a[x]=y;
	}
	Work(1,n);
	printf("%I64d",ans);
}