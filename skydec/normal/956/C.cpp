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
int n,a[N];
int b[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	int pre=0;
	LL ans=0;
	per(i,n,1){
		b[i]=max(b[i+1]-1,a[i]+1);
	}
	rep(i,1,n){
		if(pre+1==b[i]){
			++pre;
		}
		ans+=pre-a[i]-1;
	}
	printf("%lld\n",ans);
	return 0;
}