#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b,x[MAXN],y[MAXN];
bool check(int i,int j,int k,int l)
{
	if((k<=i&&l<=j)||(k<=j&&l<=i)) return true;
	return false;
}
int main()
{
	int ans=0;
	scanf("%d%d%d",&n,&a,&b);
	if(a>b) swap(a,b);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]>y[i]) swap(x[i],y[i]);
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			bool f=false;
			if(y[i]<=b) f|=check(a-x[i],b,x[j],y[j]);
			if(x[i]<=b) f|=check(a-y[i],b,x[j],y[j]);
			if(y[i]<=a) f|=check(a,b-x[i],x[j],y[j]);
			if(x[i]<=a) f|=check(a,b-y[i],x[j],y[j]);
			if(f) ans=max(ans,x[i]*y[i]+x[j]*y[j]);
		}
	printf("%d\n",ans);
	return 0;
}