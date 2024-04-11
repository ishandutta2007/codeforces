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
int n;int res;
int l[105],r[105];
int main(){
	scanf("%d",&n);rep(i,1,n)scanf("%d%d",&l[i],&r[i]);
	rep(pos,l[1],r[1]-1){
		bool f=1;
		rep(i,2,n)if(l[i]<=pos&&r[i]>pos)f=0;
		res+=f;
	}
	printf("%d\n",res);
	return 0;
}