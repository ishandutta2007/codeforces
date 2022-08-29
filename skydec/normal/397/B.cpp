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
int t;
int main(){
	scanf("%d",&t);
	while(t--){
		int n,l,r;
		scanf("%d%d%d",&n,&l,&r);
		if(n%l<=(r-l)*1ll*(n/l))printf("Yes\n");else printf("No\n");
	}
	return 0;
}