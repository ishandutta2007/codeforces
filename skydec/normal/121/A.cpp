#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j),__tmp=k;i<=__tmp;i++)
#define per(i,j,k) for(int i=(j),__tmp=k;i>=__tmp;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
LL q[3000];
map<LL,bool>ls;
void dfs(LL x){
	if(ls[x])return;
	ls[x]=1;
	if(x>4444444444ll)return;
	if(x)q[++q[0]]=x;
	dfs(x*10ll+4);
	dfs(x*10ll+7);
}
LL work(int n){
	if(!n)return 0;
	LL res=0;q[0]=0;ls.clear();
	dfs(0);
	sort(q+1,q+1+q[0]);
	//printf("%I64d\n",q[1]);
	if(n<=q[1])return n*q[1];
	res+=q[1]*q[1];
	for(int i=2;i<=q[0];i++){
		//printf("%I64d %d\n",q[i],n);
		if(q[i]>=n){
			//printf("%I64d %d\n",q[i],n);
			res+=(n-q[i-1])*q[i];
			return res;
		}
		res+=(q[i]-q[i-1])*q[i];
	}
	return res;
}
int l,r;
int main(){
	scanf("%d%d",&l,&r);
	printf("%I64d\n",work(r)-work(l-1));
	return 0;
}