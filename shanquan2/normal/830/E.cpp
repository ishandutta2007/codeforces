#include<bits/stdc++.h>
using namespace std;

struct edge{
	int nxt,to;
}e[200005];
int n,m,cnt,cn,cm,ft[100005],d[100005],c[100005],ans[100005];
bool v[100005];
vector<int> a[3],b;
void dfs(int x){
	c[cn++]=x;cm+=d[x];v[x]=1;
	for(int i=ft[x];i;i=e[i].nxt)if(!v[e[i].to])dfs(e[i].to);
}
void dfs2(int x,int fa){
	b.push_back(x);
	for(int i=ft[x];i;i=e[i].nxt)if(e[i].to!=fa)dfs2(e[i].to,x);
}
bool cmp(vector<int> a,vector<int> b){return a.size()<b.size();}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)ft[i]=v[i]=d[i]=ans[i]=0;
	cnt=1;
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		e[cnt]=(edge){ft[x],y};ft[x]=cnt++;
		e[cnt]=(edge){ft[y],x};ft[y]=cnt++;
		d[x]++;d[y]++;
	}
	for(int i=1;i<=n;i++)if(!v[i]){
		cn=cm=0;dfs(i);cm/=2;
		if(cm>=cn){
			for(int i=0;i<cn;i++)ans[c[i]]=1;
			printf("YES\n");
			for(int i=1;i<=n;i++)printf("%d ",ans[i]);printf("\n");
			return;
		}
		int k=0;
		for(int i=0;i<cn;i++)if(d[c[i]]==1)k++;
		if(k>=4){
			for(int i=0;i<cn;i++)if(d[c[i]]==1)ans[c[i]]=1;else ans[c[i]]=2;
			printf("YES\n");
			for(int i=1;i<=n;i++)printf("%d ",ans[i]);printf("\n");
			return;
		}else if(k>=3){
			int t,D=0;
			for(int i=0;i<cn;i++)if(d[c[i]]==3)t=c[i];
			for(int i=ft[t];i;i=e[i].nxt){
				b.clear();
				dfs2(e[i].to,t);
				a[D++]=b;
			}
			sort(a,a+3,cmp);
			int e[3];
			for(int i=0;i<3;i++)e[i]=a[i].size()+1;
			if(e[0]>=3)e[0]=e[1]=e[2]=3;
			else if(e[1]==2)continue;
			else if(e[1]==3){
				if(e[2]<6)continue;
				e[2]=6;
			}else e[1]=e[2]=4;
			int w=e[0];
			w=w*e[1]/gcd(w,e[1]);w=w*e[2]/gcd(w,e[2]);
			ans[t]=w;
//			for(int i=0;i<3;i++)printf("%d ",e[i]);printf("\n");
			for(int i=0;i<3;i++){
				int d=w/e[i];
				for(int j=0;j<a[i].size();j++)ans[a[i][j]]=max(w-d*(j+1),d);
			}
			printf("YES\n");
			for(int i=1;i<=n;i++)printf("%d ",ans[i]);printf("\n");
			return;
		}
	}
	printf("NO\n");
}
int main(){
	int T;scanf("%d",&T);
	while(T--)solve();
	return 0;
}