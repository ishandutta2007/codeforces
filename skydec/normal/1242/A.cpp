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
int main(){
	LL n;scanf("%lld",&n);LL on=n;
	if(n==1){
		puts("1");
		return 0;
	}
	vector<LL> d;
	for(int i=2;i*1ll*i<=n;i++)if(n%i==0){
		while(n%i==0){
			d.pb(i);
			n/=i;
		}
	} 
	if(n>1)d.pb(n);
	if(d.size()==1){
		printf("%lld\n",d[0]);
		return 0;
	}
	rep(i,0,d.size()-1)rep(j,0,d.size()-1)if(d[i]!=d[j]){
		printf("1\n");
		return 0;
	}
	printf("%lld\n",d[0]);
	return 0;
}