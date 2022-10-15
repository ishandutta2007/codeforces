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
int main()
{
	scanf("%d",&n);
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1) cnt1++; else cnt2++;
	}
	printf("%d\n",min(cnt1,cnt2)+max(0,(cnt1-cnt2)/3));
	return 0;
}