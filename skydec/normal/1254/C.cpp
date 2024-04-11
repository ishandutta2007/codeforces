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
const int N=1005;
int n;
LL q1(int i,int j,int k){
	printf("%d %d %d %d\n",1,i,j,k);
	fflush(stdout);
	LL x;scanf("%lld",&x);
	return x;
}
int q2(int i,int j,int k){
	printf("%d %d %d %d\n",2,i,j,k);
	fflush(stdout);
	int x;scanf("%d",&x);
	return x;
}
int main(){
	scanf("%d",&n);
	vector<int> up,down;
	rep(i,3,n)if(q2(1,i,2)==-1)up.pb(i);
	else down.pb(i);

	if(up.size()){
		vector<pair<LL,int> >gt;
		for(int x:up)gt.pb(pair<LL,int>(q1(1,2,x),x));
		sort(gt.begin(),gt.end());
		reverse(gt.begin(),gt.end());
		vector<int> lp;
		vector<int> rp;
		int da=gt[0].se;
		rep(i,1,gt.size()-1){
			int x=gt[i].se;
			if(q2(1,x,da)<0)lp.pb(x);
			else rp.pb(x);
		}
		up.clear();
		per(i,lp.size()-1,0)up.pb(lp[i]);
		up.pb(da);
		rep(i,0,rp.size()-1)up.pb(rp[i]);
	}
	if(down.size()){
		vector<pair<LL,int> >gt;
		for(int x:down)gt.pb(pair<LL,int>(q1(1,2,x),x));
		sort(gt.begin(),gt.end());
		reverse(gt.begin(),gt.end());
		vector<int> lp;
		vector<int> rp;
		int da=gt[0].se;
		rep(i,1,gt.size()-1){
			int x=gt[i].se;
			if(q2(1,x,da)>0)lp.pb(x);
			else rp.pb(x);
		}
		down.clear();
		per(i,lp.size()-1,0)down.pb(lp[i]);
		down.pb(da);
		rep(i,0,rp.size()-1)down.pb(rp[i]);
	}
	vector<int> ans;
	for(int x:up)ans.pb(x);
	ans.pb(2);
	per(i,down.size()-1,0)ans.pb(down[i]);
	ans.pb(1);
	printf("0 ");per(i,ans.size()-1,0)printf("%d ",ans[i]);puts("");fflush(stdout);
	return 0;
}