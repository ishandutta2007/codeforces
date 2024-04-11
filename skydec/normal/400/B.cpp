#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int n,m;char a[1005];int u[1005];
int main(){
	scanf("%d%d",&n,&m);int ans=0;
	rep(i,1,n){
		scanf("%s",a+1);
		int L,R;
		L=R=-1;
		rep(j,1,m)if(a[j]=='G')L=j;else if(a[j]=='S')R=j;
		if(L>R){
			printf("-1\n");
			return 0;
		}
		if(!u[R-L]){
			u[R-L]=1;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}