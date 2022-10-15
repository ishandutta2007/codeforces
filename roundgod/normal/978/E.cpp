#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,w,a[MAXN];
int main()
{
	scanf("%d%d",&n,&w);
	int mini=0,maxi=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int s=0;
	for(int i=1;i<=n;i++) s+=a[i],mini=min(mini,s),maxi=max(maxi,s);
	maxi=w-maxi,mini=-mini;
	printf("%d\n",max(0,maxi-mini+1));
	return 0;
}