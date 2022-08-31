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
int a[N],h,n;
int main(){
	scanf("%d",&h);
	rep(i,0,h)scanf("%d",&a[i]);
	bool flg=0;
	int t=0;
	rep(i,1,h-1)if(a[i]>1&&a[i+1]>1){flg=1;t=i;break;}
	if(!flg){
		printf("perfect\n");
		return 0;
	}
	printf("ambiguous\n");

	int rt=1;
	printf("0 ");
	n=1;
	rep(i,1,h){
		int pv=n;
		rep(j,1,a[i]){
			++n;printf("%d ",pv);
		}
	}

	rt=1;
	puts("");
	printf("0 ");
	n=1;
	rep(i,1,h){
		int pv=n;
		rep(j,1,a[i]){
			++n;
			if(j==a[i]&&i==t+1)printf("%d ",pv-1);
			else
			printf("%d ",pv);
		}
	}
	puts("");
	return 0;
}