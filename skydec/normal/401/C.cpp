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
int a,b;int p[2010000];
int main(){
	scanf("%d%d",&a,&b);
	if(b<a-1||b>a*2+2){
		printf("-1\n");
		return 0;
	}
	if(b<=a){
		rep(i,1,a){
			printf("0");
			if(b){
				b--;printf("1");
			}
		}
		return 0;
	}
	while(b){
		for(int i=0;i<=a&&b;i++){p[i]++;b--;}
	}
	rep(i,0,a){
		if(i)printf("0");
		rep(j,1,p[i])printf("1");
	}
	return 0;
}