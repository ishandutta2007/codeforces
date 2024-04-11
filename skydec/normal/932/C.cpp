#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
int n,a,b;
void work(int x,int y){
	int pre=0;
	rep(t,1,x){
		rep(j,1,a-1)printf("%d ",pre+j+1);
		printf("%d ",pre+1);
		pre+=a;
	}
	rep(t,1,y){
		rep(j,1,b-1)printf("%d ",pre+j+1);
		printf("%d ",pre+1);
		pre+=b;
	}
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	rep(i,0,n/a)if((n-(i*a))%b==0){
		work(i,(n-(i*a))/b);
		return 0;
	}
	printf("-1\n");
	return 0;
}