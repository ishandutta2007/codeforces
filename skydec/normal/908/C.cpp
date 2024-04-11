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
const int N=1005;
int n,r,x[N];
double ans[N];
int main(){
	scanf("%d%d",&n,&r);
	rep(i,1,n)scanf("%d",&x[i]);
	rep(i,1,n){
		double w=r;
		rep(j,1,i-1){
			if(abs(x[i]-x[j])<=2*r){
				w=max(w,ans[j]+sqrt(4.*r*r-(x[i]-x[j])*1.*(x[i]-x[j])));
			}
		}
		ans[i]=w;
	}
	rep(i,1,n)printf("%.10lf ",ans[i]);
	puts("");
	return 0;
}