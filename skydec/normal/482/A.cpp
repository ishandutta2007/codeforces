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
int main(){
	int n,k;scanf("%d%d",&n,&k);
	int d=n-k/2;
	printf("%d ",d);
	rep(i,1,k){
		if((i&1)^(k&1))d+=i;else d-=i;
		printf("%d ",d);
	}
	for(d--;d;d--)printf("%d ",d);
	return 0;
}