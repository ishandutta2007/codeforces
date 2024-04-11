#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,d,a[MAXN],mark[MAXN];
int main()
{
	scanf("%d%d%d",&n,&k,&d);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	a[n]=2*INF;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cnt+=mark[i];
		if(i==0||cnt>0)
		{
			int id=upper_bound(a,a+n+1,a[i]+d)-a;
			if(id-i<k) continue;
			if(id==n) {puts("YES"); return 0;}
			mark[i+k]++;
			mark[id+1]--;
		}
	}
	puts("NO");
	return 0;
}