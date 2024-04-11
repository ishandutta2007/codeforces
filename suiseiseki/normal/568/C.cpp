#include <cstdio>
template<typename Elem>
Elem min(Elem a,Elem b){
	return a<b?a:b;
}
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
const int Maxl=26;
const int Maxn=200;
const int Maxm=300000;
int n,m,k;
int p[305];
int a[Maxl+5],b[Maxl+5][2];
bool vis[Maxn<<1|5];
char s[Maxn+5];
int head[Maxm+5],arrive[Maxm+5],nxt[Maxm+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
bool dfs(int u){
	if(vis[u>n?u-n:u+n]){
		return 0;
	}
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(!vis[v]&&!dfs(v)){
			return 0;
		}
	}
	return 1;
}
bool check(int c){
	for(int i=1;i<=(n<<1);i++){
		vis[i]=0;
	}
	for(int i=1;i<=c;i++){
		if(!dfs(i+a[s[i]-'a'+1]*n)){
			return 0;
		}
	}
	for(int i=c+1;i<=n;i++){
		if(vis[i]){
			s[i]=b[1][0]+'a'-1;
		}
		else if(vis[i+n]){
			s[i]=b[1][1]+'a'-1;
		}
		else{
			int x=min(b[1][0],b[1][1]),y=max(b[1][0],b[1][1]);
			if(dfs(i+a[x]*n)){
				s[i]=x+'a'-1;
			}
			else if(dfs(i+a[y]*n)){
				s[i]=y+'a'-1;
			}
			else{
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	scanf("%s",s+1);
	while(s[++k]!='\0');
	k--;
	p['V']=0,p['C']=1;
	b[k+1][0]=b[k+1][1]=k+1;
	for(int i=k,t[2]={k+1,k+1};i>0;i--){
		a[i]=p[s[i]];
		t[a[i]]=i;
		b[i][0]=t[0];
		b[i][1]=t[1];
	}
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,s_1,t_1,s_2,t_2;i<=m;i++){
		scanf("%d",&x);
		scanf("%s",s);
		s_1=x+p[*s]*n;
		s_2=s_1>n?s_1-n:s_1+n;
		scanf("%d",&x);
		scanf("%s",s);
		t_1=x+p[*s]*n;
		t_2=t_1>n?t_1-n:t_1+n;
		add_edge(s_1,t_1);
		add_edge(t_2,s_2);
	}
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	if(check(n)){
		puts(s+1);
		return 0;
	}
	else if(b[1][0]==k+1||b[1][1]==k+1){
		puts("-1");
		return 0;
	}
	for(int i=n;i>0;i--){
		int c=s[i]-'a'+2;
		int x=min(b[c][0],b[c][1]),y=max(b[c][0],b[c][1]);
		if(x!=k+1){
			s[i]=x+'a'-1;
			if(check(i)){
				puts(s+1);
				return 0;
			}
		}
		if(y!=k+1){
			s[i]=y+'a'-1;
			if(check(i)){
				puts(s+1);
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}