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
int a[N],b[N],n;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	multiset<LL> gt;
	LL pre=0;
	rep(i,1,n){
		gt.insert(a[i]+pre);
		pre+=b[i];
		LL ans=b[i]*1ll*gt.size();
		while((*gt.begin())<pre){
			ans-=pre-(*gt.begin());
			gt.erase(gt.begin());
		}
		printf("%lld ",ans);
	}
	puts("");
	return 0;
}