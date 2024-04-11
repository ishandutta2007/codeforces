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
vector<int> ans;
void work(LL p,int k){
	if(p==0){
		return;
	}
	if(p<0){
		LL v=((-p+k-1)/k);
		ans.push_back(((-p+k-1)/k)*1ll*k+p);
		work(v,k);
	}
	else{
		LL v=-p/k;
		ans.push_back(p%k);
		work(v,k);
	}
}
int main(){
	LL p;int k;scanf("%lld%d",&p,&k);
	work(p,k);
	printf("%d\n",ans.size());
	rep(i,0,ans.size()-1)printf("%d ",ans[i]);
	return 0;	
}