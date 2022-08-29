#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int n;char a[110000];int ans[110000];
int main(){
	scanf("%s",a+1);n=strlen(a+1);
	int tl,tr,tc;tl=tr=tc=0;
	rep(i,1,n)if(a[i]=='(')tl++;
	else if(a[i]==')')tr++;
	else tc++;
	if(tc>(tl-tr)){
		printf("-1");
		return 0;
	}
	int res=0;bool fl=0;int u=0;
	for(int i=1;i<=n;i++){
		if(a[i]==')')res--;
		else if(a[i]=='(')res++;
		if(res<0){
			printf("-1\n");
			return 0;
		}
		if(a[i]=='#'){
			if(u!=tc-1)ans[++u]=1,res--;
			else {ans[++u]=tl-tr-(tc-1);res-=ans[u];}
			if(res<0){printf("-1");return 0;}
		}
	}
	rep(i,1,tc)printf("%d\n",ans[i]);
	return 0;
}