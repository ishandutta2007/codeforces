#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;

int n,ft[1000100],m=0,d[1000100];
struct edge{
	int to,id,nxt;
}e[1000100];
void addedge(int x,int y,int id){
	e[m].to=y;e[m].id=id;e[m].nxt=ft[x];ft[x]=m++;
}
int last[1000100];
bool use[1000100],cl[1000100];
void dfs(int x,bool f){
	for(;last[x]!=-1;last[x]=e[last[x]].nxt)
		if(!use[last[x]]){
			use[last[x]]=1;
			use[last[x]^1]=1;
			cl[e[last[x]].id]=f;
			dfs(e[last[x]].to,!f);
		}
}
int main(){
	scanf("%d",&n);
	memset(ft,-1,sizeof(ft));
	for(int i=0;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);x--,y--;
		addedge(x,y+N,i);addedge(y+N,x,i);
		d[x]++,d[y+N]++;
	}
	int lst=-1,o=N*2;
	for(int i=0;i<N*2;i++)
		if(d[i]&1)
			if(lst==-1)lst=i;
			else{
				if(i<N && lst>=N || i>=N && lst<N){
					addedge(lst,i,n+1);addedge(i,lst,n+1);
				}else{
					addedge(lst,o,n+1);addedge(o,lst,n+1);
					addedge(i,o,n+1);addedge(o++,i,n+1);
				}
				lst=-1;
			}
/*	for(int i=0;i<m;i++){
		if(ft[i]==-1)continue;
		for(int j=ft[i];j!=-1;j=e[j].nxt)
			printf("%d %d %d\n",i,e[j].to,e[j].id);
	}*/
	for(int i=0;i<o;i++)last[i]=ft[i];
	for(int i=0;i<o;i++)
		if(ft[i]!=-1)
			dfs(i,0);
	for(int i=0;i<n;i++)
		if(cl[i])printf("r");else printf("b");
	printf("\n");
	return 0;
}