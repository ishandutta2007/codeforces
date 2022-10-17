#include <map>
#include <cstdio>
using namespace std;
map<int,int> m;
int h,q;
double dfs(int u,int mx){
	if(mx>=m[u]){
		return mx;
	}
	int l=2*u,r=2*u+1;
	return 0.5*(dfs(l,max(mx,m[u]-m[l]))+dfs(r,max(mx,m[u]-m[r])));
}
int main(){
	scanf("%d%d",&h,&q);
	while(q--){
		char op[10];
		scanf("%s",op);
		if(op[0]=='a'){
			int v,e;
			scanf("%d%d",&v,&e);
			while(v){
				m[v]+=e;
				v/=2;
			}
		}
		else{
			printf("%.10f\n",dfs(1,0));
		}
	}
	return 0;
}