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
const int N=1100;
int n;
int w[N],h[N];
int lu[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&w[i],&h[i]);
	int ans=2000000000;
	for(int Mh=0;Mh<=1000;Mh++){
		int cnt=0;
		rep(i,1,n){
			if(h[i]>Mh&&w[i]>Mh)cnt+=n;
			else if(h[i]>Mh)cnt++;
		}
		if(cnt>n/2)continue;
		
		int cost=0;int m=0;
		rep(i,1,n){
			if(h[i]>Mh)cost+=h[i];
			else {cost+=w[i];if(w[i]<=Mh)lu[++m]=h[i]-w[i];}
		}
		sort(lu+1,lu+1+m);
		
		for(int i=1;i<=min(m,n/2-cnt);i++)if(lu[i]<0)cost+=lu[i];
		
		if(cost*Mh<ans)ans=cost*Mh;
	}
	printf("%d\n",ans);
	return 0;
}