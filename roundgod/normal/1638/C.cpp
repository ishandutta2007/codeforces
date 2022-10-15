#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		vector<int> v;
		for(int i=1;i<=n;i++)
		{
			int x=a[i];
			while(v.size()>=1&&v.back()>a[i]) {x=max(x,v.back()); v.pop_back();} 
			v.push_back(x);
		}
		printf("%d\n",(int)v.size());
	}
	return 0;
}