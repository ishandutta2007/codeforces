#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1e6+2;
ull h[N];
int p[N];
bool ed[N],flg[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
	unordered_map<ull,int> mp;
	int n,m=0,i,j,k;
	ull tot=0;
	cin>>n;
	for (i=2;i<=n;i++)
	{
		if (!ed[i]) p[m++]=i,h[i]=rnd();
		for (j=0;j<m&&(k=i*p[j])<=n;j++)
		{
			ed[k]=1;
			h[k]=h[i]^h[p[j]];
			if (i%p[j]==0) break;
		}
		if (1^n-i&1) tot^=h[i];
	}
	for (i=3;i<=n;i++) h[i]^=h[i-1];
	fill(flg+1,flg+n+1,1);
	if (tot==0) goto out;
	for (i=1;i<=n;i++) if (tot==h[i]) {flg[i]=0;goto out;}
	for (i=1;i<=n;i++)
	{
		auto it=mp.find(tot^h[i]);
		if (it!=mp.end()) {flg[i]=flg[it->second]=0;goto out;}
		mp[h[i]]=i;
	}
	flg[n>>1]=flg[2]=flg[n]=0;
	out:cout<<accumulate(flg+1,flg+n+1,0)<<'\n';
	for (int i=1;i<=n;i++) if (flg[i]) cout<<i<<' ';
}