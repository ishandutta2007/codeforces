#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define maxn 1005

int n;
long long cnt[maxn];
double f[maxn][maxn],P[maxn];

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
	{
		long long l,r;
		cin >> l >> r;
		long long pw=1;
		cnt[i]=0;
		for (int len=0;len<19;++len)
		{
			long long left=pw,right=pw+pw-1;
			
			left=max(left,l);
			right=min(right,r);
			
			if (left<=right)
				cnt[i]+=right-left+1;
			
			pw*=10;
		}
		
		//cout << cnt[i] << endl;
		P[i]=(double)cnt[i]/(r-l+1);
	}
	
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for (int i=0;i<n;++i)
		for (int j=0;j<=i;++j)
		{
			f[i+1][j]+=f[i][j]*(1-P[i]);
			f[i+1][j+1]+=f[i][j]*P[i];
		}
	
	int limit;
	scanf("%d",&limit);
	
	double ans=0;
	for (int j=0;j<=n;++j)
	if (j*100>=limit*n)
		ans+=f[n][j];
	
	printf("%.9f\n",ans);
	
	return 0;
}