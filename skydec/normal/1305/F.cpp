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
const int N=210000;
const int M=1100000;
int n;LL a[N];
LL v[N*2];
bool ispr[M+5];
int calc(LL p,int up){
	LL res=0;
	rep(i,1,n){
		if(a[i]<p)res+=p-a[i];
		else res+=min(p-a[i]%p,a[i]%p);
		if(res>up)return up;
	}
	return (int)res;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	int ans=calc(2,n);

	LL S=max(a[1]-n,1ll);
	LL T=a[1]+n;
	rep(i,0,(int)(T-S))v[i]=i+S;
	rep(i,2,M)if(!ispr[i])rep(j,2,n/i)ispr[i*j]=1;

	rep(i,2,M)if(!ispr[i]){
		bool flg=0;
		for(LL j=(i-(S%i))%i;j<=T-S;j+=i){
			while(v[j]%i==0)v[j]/=i;
			flg=1;
		}
		if(flg)ans=min(ans,calc(i,ans));
	}

	rep(i,0,(int)(T-S))if(v[i]>1)ans=min(ans,calc(v[i],ans));
	printf("%d\n",ans);
	return 0;
}