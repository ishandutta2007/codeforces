#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

int N,M,xc,yc,a[500005],f[500005],hash[500005];

int main()
{
	scanf("%d %d",&N,&M);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		hash[a[i]]=i;
	}
	for (int i=1;i<=N;i++) f[i]=N+1;
	for (int i=1;i<=M;i++)
	{
		scanf("%d %d",&xc,&yc);
		xc=hash[xc],yc=hash[yc];
		if (xc>yc) swap(xc,yc);
		f[xc]=min(f[xc],yc);
	}
	for (int i=N-1;i>=1;i--)
		f[i]=min(f[i],f[i+1]);
	LL ans=0;
	for (int i=1;i<=N;i++)
		ans+=(f[i]-i);
	cout<<ans<<endl;
	return 0;
}