#include<cstdio>
#include<vector>
#include<cstring>
#define inf (1<<30)
using namespace std;

vector<int> to[200],flw[200],cst[200],ptn[200];
int ct[26],a[200],S=0,T=127;
char st[200];
void addedge(int x,int y,int w,int c){
	ptn[x].push_back(to[y].size());ptn[y].push_back(to[x].size());
	to[x].push_back(y);to[y].push_back(x);
	flw[x].push_back(w);flw[y].push_back(0);
	cst[x].push_back(c);cst[y].push_back(-c);
}
int dist[200],q[200000],ans,pre[200];
bool inq[200];
bool bfs(){
	memset(dist,-1,sizeof(dist));
	memset(inq,0,sizeof(inq));
	int h=0,t=1;q[0]=S;dist[S]=0;inq[S]=1;
	while(h<t){
		int u=q[h++];inq[u]=0;
		for(int i=0;i<to[u].size();i++)if((dist[to[u][i]]==-1 || dist[u]+cst[u][i]<dist[to[u][i]]) && flw[u][i]){
			int v=to[u][i];
			dist[to[u][i]]=dist[u]+cst[u][i];
			pre[to[u][i]]=ptn[u][i];
			if(!inq[to[u][i]])q[t++]=to[u][i],inq[to[u][i]]=1;
		}
	}
	return dist[T]!=-1;
}
int main(){
	scanf("%s",st);
	int tot=0;
	for(int i=0;i<strlen(st);i++)
		ct[st[i]-'a']++;
	int n;scanf("%d",&n);
	for(int i=0;i<26;i++){
		addedge(n+i+1,T,ct[i],0);
		tot+=ct[i];
	}
	for(int i=0;i<n;i++){
		scanf("%s",st);
		scanf("%d",&a[i]);
		addedge(S,i+1,a[i],0);
		memset(ct,0,sizeof(ct));
		for(int j=0;j<strlen(st);j++)
			ct[st[j]-'a']++;
		for(int j=0;j<26;j++)
			if(ct[j]>0)addedge(i+1,n+j+1,ct[j],i+1);
	}
	ans=0;
	int t=0;
	while(bfs()){
		int mn=inf;
		for(int i=T;i!=S;i=to[i][pre[i]])
			mn=min(mn,flw[to[i][pre[i]]][ptn[i][pre[i]]]);
		ans+=mn*dist[T];
		for(int i=T;i!=S;i=to[i][pre[i]]){
			flw[to[i][pre[i]]][ptn[i][pre[i]]]-=mn;
			flw[i][pre[i]]+=mn;
		}
		t+=mn;
	}
	if(t<tot)printf("-1\n");else printf("%d\n",ans);
	return 0;
}