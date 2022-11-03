#include<cstdio>
using namespace std;

int next[300000],ls[300000];
bool vis[300000]={0};
int getnext(int x){
	return (vis[next[x]])?next[x]=getnext(next[x]):next[x];
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)next[i]=i+1;
	for(int i=0;i<m;i++){
		int l,r,w;
		scanf("%d%d%d",&l,&r,&w);
		l--;r--;w--;
		int st;
		if(vis[l])st=getnext(l);else st=l;
		int nxt;
		for(int i=st;i<=r;i=nxt){
			nxt=next[i];
			if(i!=w && !vis[i]){
				ls[i]=w;
				if(i<w)next[i]=w;else next[i]=next[r];
				vis[i]=1;
//				printf("%d\n",i);
			}
		}
		ls[w]=-1;next[w]=next[r];
//		for(int i=0;i<n;i++)printf("%d ",next[i]);printf("\n");
//		for(int i=0;i<n;i++)printf("%d ",vis[i]);printf("\n");
	}
	for(int i=0;i<n-1;i++)
		printf("%d ",ls[i]+1);
	printf("%d\n",ls[n-1]+1);
	return 0;
}