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
int main(){
	int n,m;
	scanf("%d%d",&n,&m);int sum=0;
	rep(i,1,n){
		int x;scanf("%d",&x);sum+=x;
	}
	if(sum<0)sum*=-1;
	if(!sum)printf("0");
	else printf("%d\n",(sum-1)/m+1);
	return 0;
}