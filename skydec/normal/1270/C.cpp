#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
int n;
void Main(){
	scanf("%d",&n);
	LL s=0;
	LL xx=0;
	rep(i,1,n){
		int w;scanf("%d",&w);
		xx^=w;
		s+=w;
	}
	printf("2\n");
	printf("%lld %lld\n",xx,(s+xx));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)Main();
	return 0;	
}