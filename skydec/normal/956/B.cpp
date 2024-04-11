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
const int N=110000;
int e[N],n,U;
int main(){
	scanf("%d%d",&n,&U);
	rep(i,1,n)scanf("%d",&e[i]);
	int t=n;
	double ans=-1;
	per(i,n-2,1){
		while(t-1>i+1&&e[t]-e[i]>U)--t;
		if(e[t]-e[i]<=U&&t>i+1){
			ans=max(ans,((e[t]-e[i+1])*1.)/(e[t]-e[i]));
		}
	}
	if(ans<0)puts("-1");
	else printf("%.13lf\n",ans);
	return 0;
}