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
const int N=1010000;
int n;
int f[N];
bool is[N];
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		for(int j=i*2;j<=n;j+=i)is[j]=1;
	}
	memset(f,63,sizeof f);
	rep(i,2,n)if(!is[i]){
		for(int j=i*2;j<=n;j+=i)f[j]=min(f[j],(j/i-1)*i+1);
		f[i]=min(f[i],i);
	}
	int ans=n;
	per(i,n-2,1){
		f[i]=min(f[i],f[i+1]);
	}
	for(int x=2;x<n;x++)if(!is[x])if(n%x<=0){
		int d=(n/x-1)*x;
		ans=min(ans,f[d+1]);
	}
	printf("%d\n",ans);
	return 0;	
}