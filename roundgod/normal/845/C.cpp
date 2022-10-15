#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,l[MAXN],r[MAXN],ans[2*MAXN];
map<int,int> mp;
set<int> s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		r[i]++;
		s.insert(l[i]);
		s.insert(r[i]);
	}
	int t=1;
	for(auto it=s.begin();it!=s.end();it++)
		mp[(*it)]=t++;
	for(int i=1;i<=n;i++)
		{l[i]=mp[l[i]]; r[i]=mp[r[i]];}
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)
		{ans[l[i]]++; ans[r[i]]--;}
	for(int i=1;i<=2*n;i++)
		ans[i]+=ans[i-1];
	for(int i=1;i<=2*n;i++)
		if(ans[i]>2) {puts("NO"); return 0;}
	puts("YES");
	return 0;
}