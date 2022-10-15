#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,s,cnt[MAXN];
int a[MAXN];
bool C(int len)
{
	int sum=0;
	for(int i=1;i<=len;i++) if(cnt[i]==0) sum++;
	for(int i=1;i<=n;i++) {if(a[i]>len) sum--; if(a[i]==1&&i!=s) sum--;}
	return sum>0;
}
int main()
{
	scanf("%d%d",&n,&s);
	int ans=0;
	int res=0;
	for(int i=1;i<=n;i++) {scanf("%d",&a[i]); if(a[i]==0&&i!=s)res++; a[i]++;}
	if(a[s]!=1) {a[s]=1; ans++;}
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	int l=0,r=n+1;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(C(mid)) r=mid; else l=mid;
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<=l;i++)
		if(cnt[i]==0) cnt1++;
	for(int i=1;i<=n;i++)
		if(a[i]==1&&i!=s) cnt2++;
	ans+=max(cnt1,cnt2);
	printf("%d\n",ans);
	return 0;
}