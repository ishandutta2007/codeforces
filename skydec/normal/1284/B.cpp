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
int n;
int bg[N],sm[N];
int a[N];
int main(){
	int _n;scanf("%d",&_n);
	LL res=_n*1ll*_n;
	while(_n--){
		int k;scanf("%d",&k);
		rep(i,1,k)scanf("%d",&a[i]);
		bool flg=1;
		rep(i,2,k)flg&=(a[i-1]>=a[i]);
		if(!flg)continue;
		++n;
		bg[n]=a[1];
		sm[n]=a[k];
	}
	sort(bg+1,bg+1+n);
	sort(sm+1,sm+1+n);
	int t=0;
	rep(i,1,n){
		while(t+1<=n&&bg[t+1]<=sm[i])++t;
		res-=t;
	}
	printf("%lld\n",res);
	return 0;
}