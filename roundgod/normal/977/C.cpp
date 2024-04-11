#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int C(int x)
{
	int cnt=0;
	for(int i=0;i<n;i++)
		if(a[i]<=x) cnt++;
	return cnt;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int l=1,r=INF+1;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(C(mid)<=k) l=mid; else r=mid;
	}
	if(C(l)==k) printf("%d\n",l); else puts("-1");
	return 0;
}