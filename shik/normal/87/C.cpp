// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define N 200010
using namespace std;
typedef vector<int> VI;
typedef VI::iterator VIT;
VI fac[N];
void pre_cal() {
	for ( int i=1; i<N; i++ )
		for ( int j=i; j<N; j+=i )
			fac[j].push_back(i);
}
int sg[N],sg_sum[N],take[N];
int main()
{
	pre_cal();
	int n,i;
	scanf("%d",&n);
	for ( i=1; i<=n; i++ ) {
		VI v;
		take[i]=-1;
		for ( VIT it=fac[2*i].begin(); it!=fac[2*i].end(); it++ ) {
			int k=*it;
			if ( (k+2*i/k-1)%2!=0 ) continue;
			int b=(k+2*i/k-1)/2;
			int a=b+1-k;
			if ( a<=0 || a>=b || b<=0 ) continue;
			int tmt=sg_sum[b]^sg_sum[a-1];
			v.push_back(tmt);
			if ( tmt==0 && take[i]==-1 ) take[i]=k;
		}
		sort(v.begin(),v.end());
		if ( v.empty() || v[0]!=0 ) sg[i]=0;
		else {
			for ( int j=0; j<SZ(v); j++ )
				if ( j==SZ(v)-1 || v[j+1]>v[j]+1 ) {
					sg[i]=v[j]+1;
					break;
				}
		}
		sg_sum[i]=sg_sum[i-1]^sg[i];
	}
	printf("%d\n",take[n]);
	return 0;
}