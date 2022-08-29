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
const int N=1010000;
int n;int a[N];LL sa[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)sa[i]=sa[i-1]+a[i];
	if(sa[n]==1){
		puts("-1");
		return 0;
	}
	vector<LL> pr;
	LL w=sa[n];
	for(int i=2;i*1ll*i<=w;i++)if(w%i==0){
		while(w%i==0){
			w/=i;
		}
		pr.pb(i);
	}
	if(w>1)pr.pb(w);
	LL ans=1ll<<60;
	for(LL x:pr){
		LL res=0;
		rep(i,1,n-1){
			res+=min(sa[i]%x,x-(sa[i]%x));
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}