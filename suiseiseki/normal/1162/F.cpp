/*#include <cstdio>
#include <cstring>
#define Mod 998244353
#define Maxn 1000
char s[Maxn+5];
int n,m;
int head[Maxn<<1|5],arrive[Maxn<<3|5],nxt[Maxn<<3|5],val[Maxn<<3|5],tot;
int node[Maxn<<1|5];
int d[Maxn<<1|5];
void add_edge(int from,int to,int v){
	arrive[++tot]=to;
	val[tot]=v;
	nxt[tot]=head[from];
	head[from]=tot;
}
void init(){
	tot=0;
	memset(head,0,sizeof head);
	memset(node,-1,sizeof node);
}
bool dfs(int x,int num){
	if(node[x]!=-1){
		if(node[x]!=num){
			return 0;
		}
		return 1;
	}
	node[x]=num;
	for(int i=head[x];i;i=nxt[i]){
		if(!dfs(arrive[i],node[x]^val[i])){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	d[0]=1;
	for(int i=1;i<=(Maxn<<1);i++){
		d[i]=(d[i-1]<<1);
		d[i]%=Mod;
	}
	bool get_ans;
	int block;
	int ans=0;
	for(m=n-1;m>0;m--){
		init();
		for(int i=1;i<=(n>>1);i++){
			add_edge(i,n-i+1,0);
			add_edge(n-i+1,i,0);
		}
		for(int i=1;i<=(m>>1);i++){
			add_edge(n+i,n+(m-i+1),0);
			add_edge(n+(m-i+1),n+i,0);
		}
		node[n+m+1]=0;
		add_edge(1,n+m+1,1);
		add_edge(n+m+1,1,1);
		add_edge(n+1,n+m+1,1);
		add_edge(n+m+1,n+1,1);
		for(int i=1;i<=n;i++){
			if(s[i]=='?'){
				continue;
			}
			if(i<=n-m){
				add_edge(i,n+m+1,s[i]^48);
				add_edge(n+m+1,i,s[i]^48);
			}
			else{
				add_edge(i,m+i,s[i]^48);
				add_edge(m+i,i,s[i]^48);
			}
		}
		get_ans=1;
		block=0;
		block++;
		get_ans=(get_ans&&dfs(n+m+1,0));
		for(int i=1;i<=n+m&&get_ans;i++){
			if(node[i]!=-1){
				get_ans=(get_ans&&dfs(n+m+1,0));
				block++;
			}
		}
		if(get_ans){
			ans+=d[block-1];
			ans%=Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
char s[1010];
int n,ans;
int I,A[1010],B[1010],cnt,fir[2010],nxt[100010],dis[100010],id;
bool w[100010];
void link(int a,int b,int c){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	nxt[++id]=fir[b],fir[b]=id,dis[id]=a,w[id]=c;
}
int p2[2010];
bool vis[2010],col[2010];
bool dfs(int x){
	for(int i=fir[x];i;i=nxt[i]){
		if(!vis[dis[i]]){
			vis[dis[i]]=1;
			col[dis[i]]=col[x]^w[i];
			if(dfs(dis[i])){
				return 1;
			}
		}
		else if(col[dis[i]]^col[x]^w[i]){
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	p2[0]=1;
	for(int i=1;i<=2000;i++){
		p2[i]=p2[i-1]*2%mod;
	}
	for(int pa=2;pa<=n;pa++){
		memset(fir,0,sizeof fir);
		id=cnt=0;
		I=cnt++;
		for(int i=pa;i<=n;i++){
			A[i]=cnt++;
		}
		for(int i=1;i<=n;i++){
			B[i]=cnt++;
		}
		link(B[1],I,1);
		link(A[pa],I,1);
		for(int i=pa;i<=n;i++){
			if(s[i]=='0'){
				link(A[i],B[i],0);
			}
			else if(s[i]=='1'){
				link(A[i],B[i],1);
			}
		}
		for(int i=1;i<pa;i++){
			if(s[i]=='0'){
				link(B[i],I,0);
			}
			else if(s[i]=='1'){
				link(B[i],I,1);
			}
		}
		for(int i=pa,j=n;i<j;i++,j--){
			link(A[i],A[j],0);
		}
		for(int i=1,j=n;i<j;i++,j--){
			link(B[i],B[j],0);
		}
		memset(vis,0,sizeof vis);
		int C=0;
		for(int i=0;i<cnt;i++){
			if(!vis[i]){
				C++;
				if(dfs(i)){
					C=-1;
					break;
				}
			}
		}
		if(~C){
			ans=(ans+p2[C-1])%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}