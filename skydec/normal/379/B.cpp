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
int n;
int a[305];
int main(){
	scanf("%d",&n);
	int x;scanf("%d",&x);
	rep(i,1,x)printf("PRL");
	rep(i,2,n-1){
		scanf("%d",&x);printf("R");
		rep(j,1,x)printf("PRL");
	}
	scanf("%d",&x);printf("R");
	rep(i,1,x)printf("PLR");
	return 0;
}