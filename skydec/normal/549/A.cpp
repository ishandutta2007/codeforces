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
int n,m;
const int N=55;
char a[N][N];
int main(){
	int ans=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",a[i]+1);
	rep(i,1,n-1)rep(j,1,m-1){
		int opt[266];memset(opt,0,sizeof opt);
		opt[a[i][j]]++;opt[a[i+1][j]]++;
		opt[a[i][j+1]]++;opt[a[i+1][j+1]]++;
		if(opt['f']&&opt['a']&&opt['e']&&opt['c'])ans++;
	}
	printf("%d\n",ans);
	return 0;
}