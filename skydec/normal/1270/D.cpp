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
const int N=505;
int n,k;
bool a[N];
pii v[N];
pii ask(){
	printf("?");
	rep(i,1,n)if(a[i])printf(" %d",i);
	puts("");
	fflush(stdout);
	int x,y;scanf("%d%d",&x,&y);
	return pii(x,y);
}
void rp(int x){
	printf("! %d\n",x);
	fflush(stdout);
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)a[i]=(i<=k);
	pii ori=ask();
	rep(i,1,k)if(i!=ori.fi){
		a[i]=0;
		a[k+1]=1;
		v[i]=ask();
		a[i]=1;
		a[k+1]=0;
	}
	int hit=0;
	int bg=-1;
	rep(i,1,k)if(i!=ori.fi){
		if(v[i].se==ori.se)hit++;
		else{
			bg=(v[i].se>ori.se);
		}
	}
	if(bg!=-1){
		if(bg==1){
			rp(k-hit);
		}
		else{
			rp(hit+1);
		}
	}
	else{
		rep(i,1,k+1)a[i]=1;a[ori.fi]=0;
		if(ask().se>ori.se)rp(1);
		else rp(k);
	}
	return 0;
}