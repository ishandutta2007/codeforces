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
int n,k,q;
const int N=5500;
int a[N];
bool cun[11000000];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n){scanf("%d",&a[i]);cun[a[i]]=1;}
	scanf("%d",&q);
	while(q--){
		int x;scanf("%d",&x);
		int ans=k+1;
		rep(i,1,n){
			for(int j=1;j<=k&&a[i]*j<=x;j++){
				if(a[i]*j==x){ans=min(ans,j);break;}
				for(int u=1;u<=k-j;u++)if((x-a[i]*j)%u==0){
					if((x-a[i]*j)/u<=10000000)if(cun[(x-a[i]*j)/u]){ans=min(ans,u+j);break;}
				}
			}
		}
		if(ans>k)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}