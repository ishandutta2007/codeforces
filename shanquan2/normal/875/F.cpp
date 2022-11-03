#include<bits/stdc++.h>
using namespace std;

struct edge{
	int x,y,w;
	bool operator <(const edge &o)const{
		return w>o.w;
	}
}e[200005];
int fa[200005],n,m;
long long ans;
bool v[200005];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e,e+m);
	for(int i=0;i<m;i++){
		int p=find(e[i].x),q=find(e[i].y);
		if(p!=q){
			if(!v[p]||!v[q]){
				v[p]=v[p]||v[q];
				ans+=e[i].w;
				fa[q]=p;
			}
		}else if(!v[p]){
			ans+=e[i].w;
			v[p]=1;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}