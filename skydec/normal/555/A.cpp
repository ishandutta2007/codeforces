#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=110000;
int a[N];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=n-2;
	rep(i,1,k){
		int cc;scanf("%d",&cc);
		ans+=cc-1;
		rep(j,1,cc){
			scanf("%d",&a[j]);
		}
		rep(j,1,cc)if(a[j]==1){
			int bb=j;
			while(bb+1<=cc&&a[bb+1]==a[bb]+1){
				bb++;ans-=2;
			}
			bb=j;
			while(bb-1>=1&&a[bb-1]==a[bb]+1){
				ans-=2;bb--;
			}
		}
	}
	printf("%d\n",ans+1);
	return 0;
}