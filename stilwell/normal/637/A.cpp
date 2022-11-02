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
int cnt[1010000];
int ans=0;
int main(){
	int n;scanf("%d",&n);
	while(n--){
		int x;scanf("%d",&x);
		if((++cnt[x])>cnt[ans])ans=x;
	}
	printf("%d\n",ans);
	return 0;
}