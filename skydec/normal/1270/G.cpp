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
int a[N];int n;
int q[N];int du[N];
void Main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)du[i]=0;
	rep(i,1,n)du[i-a[i]]++;
	q[0]=0;
	rep(i,1,n)if(!du[i])q[++q[0]]=i;
	rep(i,1,q[0]){
		int x=q[i];
		du[x-a[x]]--;
		if(!du[x-a[x]])q[++q[0]]=x-a[x];
	}
	rep(i,1,n)if(du[i]){
		vector<int> res;
		for(int x=i-a[i];;x=x-a[x]){
			res.pb(x);
			if(x==i)break;
		}
		printf("%d\n",res.size());
		for(int x:res)printf("%d ",x);puts("");
		return;
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)Main();
	return 0;
}