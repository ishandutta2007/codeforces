#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN], b[MAXN];
int f[MAXN][MAXN];

int main(void)
{
	int n,l,d;
	scanf("%d%d%d",&n,&l,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	int ans = inf;
	memset(f, 0x3f, sizeof(f));
	f[1][1] = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=i; ++j) if(f[i][j] < inf)
		{
			if(n-j <= d)
				ans = min((ll)ans, (ll)f[i][j] + (ll)(l - a[i]) * b[i]);
			for(int k=i+1; k<=n; ++k)
				f[k][j+1] = min((ll)f[k][j+1], (ll)f[i][j] + (ll)(a[k] - a[i]) * b[i]);
		}
	printf("%d",ans);
	return 0;
}