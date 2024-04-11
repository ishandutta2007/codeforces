#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
map<int,int> mp;
vector<P> ans;
vector<P> op;
vector<int> v;
void rev_suffix(int len)
{
	for(int i=1;i<=len;i++)
	{
		op.push_back(P(n-len-1+i,a[n+1-i]));
	}
	reverse(a+n-len+1,a+n+1);
	v.push_back(2*len);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mp.clear();
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			mp[a[i]]++;
		}
		bool f=true;
		for(auto p:mp)
		{
			if(p.S&1) {f=false; break;}
		}
		if(!f) {puts("-1"); continue;}
		ans.clear(); op.clear(); v.clear();
		int cur=0,offset=0;
		for(int i=1;i<=n;i+=2)
		{
			if(a[i]!=a[i+1])
			{
				int pos=-1;
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]==a[i])
					{
						pos=j;
						break;
					}
				}
				assert(pos!=-1);
				rev_suffix(n-pos+1);
				rev_suffix(n-i);
			}
		}
		printf("%d\n",(int)op.size());
		for(auto p:op) printf("%d %d\n",p.F,p.S);
		reverse(v.begin(),v.end());
		printf("%d\n",n/2+(int)v.size());
		for(int i=1;i<=n/2;i++) printf("%d ",2);
		for(auto x:v) printf("%d ",x);
		puts("");
	}
	return 0;
}