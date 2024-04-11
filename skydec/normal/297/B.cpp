#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
int tot=1;
const int N=110000;
int ma[N*35];int tag[N*35];
int cl[N*35],cr[N*35];
int n,m,k;
void add(int &me,int l,int r,int x,int y,int v){
	if(!me)me=++tot;
	if(x<=l&&r<=y){
		tag[me]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(cl[me],l,mid,x,y,v);
	if(y>mid)add(cr[me],mid+1,r,x,y,v);
	ma[me]=max(ma[cl[me]]+tag[cl[me]],ma[cr[me]]+tag[cr[me]]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);int rt=1;
	rep(i,1,n){
		int v;scanf("%d",&v);
		add(rt,1,k,1,v,1);
	}
	rep(i,1,m){
		int v;scanf("%d",&v);
		add(rt,1,k,1,v,-1);
	}
	if(ma[1]+tag[1]>0){
		printf("YES");
	}
	else printf("NO");
	return 0;
//
}