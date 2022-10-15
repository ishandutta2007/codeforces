#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,d[MAXN],ans[MAXN];
P a[MAXN];
bool cmp(P x,P y)
{
	return x.F>y.F;
}
int st[MAXN][32];
int pre[MAXN];
void init(int n,int *arr)
{
    pre[1]=0;
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n;i>=1;--i)
    {
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].F);
		a[i].S=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		d[i]=i==n?a[n].F:a[i].F-a[i+1].F;
	init(n,d);
	int x,y;
	int ans1,ans2,ans3,t1,t2,t3;
	ans1=ans2=ans3=-INF; t1=t2=t3=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=(i+1)/2;i+j<=n&&j<=i*2;j++)
		{
			if((n-i-j)*2<max(i,j)) continue;
			int res1=d[i],res2=d[i+j];
			if(res1<ans1) continue;
			if(res1==ans1&&res2<ans2) continue;
			int res3=query(i+j+max(1,(max(i,j)+1)/2),i+j+min(n-i-j,2*min(i,j)));
			if(res1==ans1&&res2==ans2&&res3<ans3) continue;
			ans1=res1; ans2=res2; ans3=res3; t1=i; t2=j; t3=res3;
		}
	}
	for(int i=t1+t2+max(1,(max(t1,t2)+1)/2);i<=t1+t2+min(n-t1-t2,2*min(t1,t2));i++)
		if(d[i]==t3) {t3=i-t1-t2; break;}
	for(int i=1;i<=t1;i++)
		ans[a[i].S]=1;
	for(int i=1;i<=t2;i++)
		ans[a[t1+i].S]=2;
	for(int i=1;i<=t3;i++)
		ans[a[t1+t2+i].S]=3;
	for(int i=t1+t2+t3+1;i<=n;i++)
		ans[a[i].S]=-1;
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}