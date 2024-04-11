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
int a,b;int res;
int main(){
	scanf("%d%d",&a,&b);int cost=0;
	while(a){
		res+=a;
		a+=cost;
		cost=a%b;
		a/=b;
	}
	printf("%d\n",res);
	return 0;
}