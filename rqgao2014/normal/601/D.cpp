#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debug puts("isok")
using namespace std;

struct node{
	int to,next;
}p[600005];
int n,tot,head[300005],c[300005],ch[300005],f[300005][26],ans,cnt,si[300005],a[300005];
char s[300005],vis[300005];
inline void add(int x,int y){
	p[++tot].to=y;p[tot].next=head[x];head[x]=tot;
	p[++tot].to=x;p[tot].next=head[y];head[y]=tot;
}
inline bool cmp(int x,int y){return si[x]>si[y];}
inline void merge(int x,int y){
	for(int i=0;i<26;i++)
		if(!f[x][i]&&f[y][i]) f[x][i]=f[y][i],si[x]+=si[f[y][i]]; else if(f[x][i]&&f[y][i]) si[x]-=si[f[x][i]],merge(f[x][i],f[y][i]),si[x]+=si[f[x][i]];
}
inline void dfs(int x){
	vis[x]=1;si[x]=1;
	for(int i=head[x];i;i=p[i].next)
		if(!vis[p[i].to]) dfs(p[i].to),vis[p[i].to]=0;
	int l=tot+1,r=tot;
	for(int i=head[x];i;i=p[i].next)
		if(!vis[p[i].to]) a[++tot]=p[i].to,vis[p[i].to]=1;
	r=tot;
	if(r>=tot){
		sort(a+l,a+r+1,cmp);
		for(int j=l;j<=r;j++){
			int i=a[j];
			if(!f[x][ch[i]]) f[x][ch[i]]=i,si[x]+=si[i]; else si[x]-=si[f[x][ch[i]]],merge(f[x][ch[i]],i),si[x]+=si[f[x][ch[i]]];
		}
	}
	if(ans<si[x]+c[x]) ans=si[x]+c[x],cnt=1; else if(ans==si[x]+c[x]) cnt++;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) ch[i]=s[i]-'a';
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	tot=0;dfs(1);
	printf("%d\n%d\n",ans,cnt);
	return 0;
}