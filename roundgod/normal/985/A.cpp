#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
	scanf("%d",&n);
	int res=0;
	for(int i=0;i<n/2;i++)
		scanf("%d",&a[i]);
	sort(a,a+n/2);
	int ans=INF;
	for(int i=0;i<n/2;i++)
		res+=max(a[i]-(i*2+1),(i*2+1)-a[i]);
	ans=min(ans,res);
	res=0;
	for(int i=0;i<n/2;i++)
		res+=max(a[i]-(i*2+2),(i*2+2)-a[i]);
	ans=min(ans,res);
	printf("%d\n",ans);
	return 0;
}