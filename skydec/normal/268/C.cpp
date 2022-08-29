#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	printf("%d\n",min(n,m)+1);
	if(n<=m){
		rep(i,0,n)printf("%d %d\n",i,n-i);
	}
	else rep(i,0,m)printf("%d %d\n",i,m-i);
	return 0;
}