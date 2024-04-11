#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=510000;
int n;int a[N];int m;LL ans=0;
int q1[N],q2[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int v;scanf("%d",&v);
		while(m>=2&&a[m-1]>=a[m]&&a[m]<=v){
			ans+=1ll*min(a[m-1],v);
			m--;
		}
		a[++m]=v;
	}
	sort(a+1,a+1+m);rep(i,1,m-2)ans+=1ll*a[i];
	printf("%I64d\n",ans);
	return 0;
}