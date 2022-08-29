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
const int N=105;
int sum[N];
char a[N][N];int n,m;
int main(){
	int ans=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",a[i]+1);
	per(i,n,1){
		int Sum=0;
		per(j,m,1){
			Sum+=sum[j];int val=1;if(a[i][j]=='B')val=-1;
			if(Sum!=val){
				ans++;sum[j]+=val-Sum;Sum=val;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}