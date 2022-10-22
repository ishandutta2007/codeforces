#include<cstdio>
#include<vector>
using namespace std;
const int o=2e5+10;
int n,m,s,h[o],cnt,lst[o],fr[o];bool flg;vector<int> v1,v2;
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void dfs(int nw,int fa,int frm){
	if(flg) return;
	if(fr[nw]){
		if(fr[nw]^frm){
			for(int i=nw;i;i=lst[i]) v1.push_back(i);
			v2.push_back(nw);flg=1;
			for(int i=fa;i;i=lst[i]) v2.push_back(i);
		}
		return;
	}
	fr[nw]=frm;lst[nw]=fa;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^s) dfs(e[i].v,nw,frm);
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int u,v;m--;) scanf("%d%d",&u,&v),ad(u,v);
	for(int i=h[s];i&&!flg;i=e[i].p) dfs(e[i].v,s,e[i].v);
	if(!flg){printf("Impossible");return 0;}
	printf("Possible\n%d\n",v1.size());
	for(int i=v1.size();i--;) printf("%d ",v1[i]);
	printf("\n%d\n",v2.size());
	for(int i=v2.size();i--;) printf("%d ",v2[i]);
	return 0;
}