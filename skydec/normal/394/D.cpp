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
#define MAXN 2005
int a[MAXN];int n;
int main(){
	scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int yao=21000000;int lowest,cha;
	rep(p,0,20001){
		int low,high;
		low=21000000;high=-210000000;
		rep(i,1,n){
			if(a[i]-(i-1)*p<low)low=a[i]-(i-1)*p;
			if(a[i]-(i-1)*p>high)high=a[i]-(i-1)*p;
		}
		if((high-low+1)/2<yao){
			yao=(high-low+1)/2;
			lowest=low+yao;
			cha=p;
		}
	}
	printf("%d\n%d %d\n",yao,lowest,cha);
	return 0;
}