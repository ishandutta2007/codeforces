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
void Main(){
	int s1=0;
	int s2=0;
	int n,k1,k2;scanf("%d%d%d",&n,&k1,&k2);
	rep(i,1,k1){int x;scanf("%d",&x);s1=max(s1,x);}
	rep(i,1,k2){int x;scanf("%d",&x);s2=max(s2,x);}
	if(s1>s2)puts("YES");
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)Main();
	return 0;
}