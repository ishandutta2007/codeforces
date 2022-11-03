#include<bits/stdc++.h>
using namespace std;

struct fe{
	int nxt,to;
}e[100005];
int n,m,a[100005],b[100005],ft[100005],cnt=1;
vector<int> s[100005];
bool v[100005];
void dfs(int x){
	if(v[x])return;
	v[x]=1;
	for(int i=ft[x];i;i=e[i].nxt)dfs(e[i].to);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int k;scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x;scanf("%d",&x);
			s[i].push_back(x);
		}
		if(i){
			bool f=1;
			for(int j=0;j<k&&j<s[i-1].size();j++)if(s[i][j]!=s[i-1][j]){
				f=0;int x=s[i-1][j],y=s[i][j];
//				printf("%d %d %d %d\n",x,y,b[x],b[y]);
				if(y>x){
					e[cnt]=(fe){ft[y],x};ft[y]=cnt++;
				}else{
					if(b[x]==2){
						printf("No\n");
						return 0;
					}
					b[x]=1;
					if(b[y]==1){
						printf("No\n");
						return 0;
					}
					b[y]=2;
				}
				break;
			}
			if(f&&k<s[i-1].size()){
				printf("No\n");
				return 0;
			}
		}
	}
//	for(int i=1;i<=m;i++)printf("%d ",b[i]);printf("\n");
	for(int i=1;i<=m;i++)if(b[i]==1)dfs(i);
//	for(int i=1;i<=m;i++)printf("%d ",v[i]);printf("\n");
	for(int i=1;i<=m;i++)if(v[i]&&b[i]==2){
		printf("No\n");
		return 0;
	}
	int ans=0;
	for(int i=1;i<=m;i++)ans+=v[i];
	printf("Yes\n");
	printf("%d\n",ans);
	for(int i=1;i<=m;i++)if(v[i])printf("%d ",i);
	return 0;
}