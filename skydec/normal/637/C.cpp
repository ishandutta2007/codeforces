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
const int N=1005;
char a[N][8];
int n;
int main(){
	scanf("%d",&n);
	int ans=6;
	rep(i,1,n)scanf("%s",a[i]+1);
	rep(i,1,n)rep(j,i+1,n){
		int c=0;
		rep(k,1,6)if(a[i][k]!=a[j][k])c++;
		ans=min(ans,(c+1)/2-1);
	}
	printf("%d\n",ans);
	return 0;
}