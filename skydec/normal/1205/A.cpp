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
const int N=110000;
int a[N*2];
int main(){
	int n;scanf("%d",&n);
	if(n%2==0){
		puts("NO");
		return 0;
	}	
	puts("YES");
	int l=1;
	int r=n+1;
	rep(i,1,n){
		if(i&1){
			a[l]=2*i;
			a[r]=2*i-1;
		}
		else{
			a[l]=2*i-1;
			a[r]=2*i;
		}
		l=(l%(2*n))+1;
		r=(r%(2*n))+1;
	}
	rep(i,1,2*n)printf("%d ",a[i]);puts("");
	return 0;
}