#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[MAXN],ans;
int cnt[51000005];
unordered_map<ll,int> mp;
unordered_map<int,int> mp2[MAXN];
const ll shift=50000000;
void solve()
{
	for(int d=1;d<=500;d++)
	{
		for(int i=1;i<=n;i++) {cnt[a[i]-d*i+shift]++; ans=max(ans,cnt[a[i]-1LL*d*i+shift]);}
		for(int i=1;i<=n;i++) cnt[a[i]-d*i+shift]--;
	}
	for(int i=1;i<=n;i++) mp2[i].clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=min(i+200,n);j++)
		{
			if((a[j]>=a[i])&&((a[j]-a[i])%(j-i)==0))
			{
				int d=(a[j]-a[i])/(j-i);
				int val=mp2[i][d]+1;
				ans=max(ans,val+1);
				mp2[j][d]=max(mp2[j][d],val);
			}
		}
	}
}
int main()
{
	ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {scanf("%d",&a[i]); cnt[a[i]]++; ans=max(ans,cnt[a[i]]);}
	for(int i=1;i<=n;i++) cnt[a[i]]--;
	solve();
	for(int i=1;i<=n;i++) a[i]=100001-a[i];
	solve();
	printf("%d\n",n-ans);
	return 0;
}