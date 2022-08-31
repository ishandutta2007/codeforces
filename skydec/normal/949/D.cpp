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
int n,d,b;
int a[N];
LL S[N];
LL suf(int x){
	return S[n]-S[x-1];
}
bool check(int L,int R){
	rep(i,L,(n+1)/2){
		if(S[min(i*1ll*(d+1),n*1ll)]<(i-L+1)*1ll*b)return 0;
	}
	rep(i,(n+1)/2+1,R){
		if(suf(n-min((n-i+1)*1ll*(d+1),n*1ll)+1)<(R-i+1)*1ll*b)return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&d,&b);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)S[i]=S[i-1]+a[i];
	int ans=(n+1)/2;
	int l=0;
	int r=(n+1)/2-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid+1,n-mid))ans=mid,r=mid;
		else l=mid+1;
	}
	if(check(l+1,n-l))ans=l;
	printf("%d\n",ans);
	return 0;
}