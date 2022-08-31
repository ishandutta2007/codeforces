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
int n,m;
const int N=210000;
int cnt[N];
int a[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int x;scanf("%d",&x);
		cnt[x%m]++;
		if(cnt[x%m]>1){
			printf("0\n");
			return 0;
		}
		a[i]=x;
	}
	int ans=1;
	rep(i,1,n)rep(j,i+1,n){
		ans=ans*1ll*(abs(a[i]-a[j]))%m;
	}
	ans=(ans%m+m)%m;
	printf("%d\n",ans);
	return 0;
}