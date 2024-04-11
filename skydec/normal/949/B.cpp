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
LL n;
int q;
LL f(LL n,LL x){
	if(x==1)return 1;
	if(x==2)return f(n-1,n-1)+1;
	if(x%2==1)return f(n-x/2,1)+x/2;
	else return f(n-(x/2-1),2)+(x/2-1);
}
int main(){
	scanf("%lld%d",&n,&q);
	while(q--){
		LL x;scanf("%lld",&x);
		printf("%lld\n",f(n,x));
	}	
	return 0;
}