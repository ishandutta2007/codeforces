#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
ll s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bool f=false;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		ll s1=a[n],s2=a[1];
		for(int i=2;i<=n;i++)
		{
			s2+=a[i];
			if(s1>s2) {f=true; break;}
			s1+=a[n+1-i];
		}
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}