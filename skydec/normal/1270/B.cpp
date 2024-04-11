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
const int N=210000;
int n,a[N];
int stk[N],t;
void Main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,2,n)if(abs(a[i]-a[i-1])>1){
		printf("YES\n");
		printf("%d %d\n",i-1,i);
		return;
	}
	printf("NO\n");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)Main();
	return 0;	
}