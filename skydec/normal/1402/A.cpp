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
int k;
int go(int x){
	if(x>=0)return x;
	x=-x;
	int t=0;
	for(int base=1;x;base*=k,x/=k)t+=((k-x%k)%k)*base;
	return t;
}
int plus_(int a,int b){
	a=go(a);
	b=go(b);
	int t=0;
	for(int base=1;a||b;base*=k,a/=k,b/=k){
		t+=(((a%k)+(b%k))%k)*base;
	}
	return t;
}
int tryit(int x){
	printf("%d\n",x);
	fflush(stdout);
	int r;scanf("%d",&r);
	return r;
}
void Main(){
	int n;scanf("%d%d",&n,&k);
	int pre=0;
	rep(i,0,n-1){
		//y-pre=i*(-1)^i
		//y=pre+i*(-1)^i
		//pre=y-pre
		int y=plus_(pre,i*(i&1?-1:1));
		if(tryit(y)){
			return;
		}
		pre=plus_(y,-pre);
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)Main();
	return 0;
}