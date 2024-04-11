#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define Maxn 10000005
#define MN 755
int n;
int add[Maxn][2],cnt=0;
int tag[Maxn];
string s[MN];
void ins(int id,string s){
	int now=0;
	for(int i=0;i<s.size();++i){
		if(!add[now][s[i]-'a'])add[now][s[i]-'a']=++cnt;	
		now=add[now][s[i]-'a'];
	}
	tag[now]=id;
}
int q[Maxn],fail[Maxn],fa[Maxn];
int G[MN][MN];
int mat[MN<<1],vis[MN<<1],ans;
void getfail(){
	int l=1,r=0;
	for(int i=0;i<2;++i)if(add[0][i])q[++r]=add[0][i];
	while(l<=r){
		int x=q[l++];
		fa[x]=tag[fail[x]]?fail[x]:fa[fail[x]];
		for(int i=0;i<2;++i)
			if(!add[x][i]) add[x][i]=add[fail[x]][i];
			else {
				q[++r]=add[x][i];
				fail[add[x][i]]=add[fail[x]][i];
			}
	}
}
bool dfs(int x){
	if(vis[x])return 0;
	vis[x]=1;
	for(int i=1;i<=n;++i){
		if(i==x)continue;
		if(G[x][i]){
			if(!mat[i+n]){
				mat[x]=i+n;
				mat[i+n]=x;
				ans++;
				return 1;
			}
			else{
				int v=mat[i+n];
				mat[x]=i+n;mat[i+n]=x;mat[v]=0;
				if(dfs(v))return 1;
				mat[x]=0;mat[i+n]=v;mat[v]=i+n;
			}
		}
	}
	return 0;
}
void DFS(int x){
	if(vis[x])return;
	vis[x]=1;
	for(int i=1;i<=n;++i){
		if(G[x][i]&&x!=i){
			vis[i+n]=1;
			DFS(mat[i+n]);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		ins(i,s[i]);
	}
	getfail();
	for(int i=1;i<=n;++i){
		int now=0;
		for(int j=0;j<s[i].size();++j){
			now=add[now][s[i][j]-'a'];
		//	cerr<<"?? "<<i<<" "<<tag[fa[now]]<<" "<<tag[now]<<endl;
			G[i][tag[now]]=1;
			G[i][tag[fa[now]]]=1;
		}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				G[i][j]=max(G[i][j],min(G[i][k],G[k][j]));
//	for(int i=1;i<=n;++i)
//		for(int j=1;j<=n;++j)
//			cerr<<i<<" "<<j<<": "<<G[i][j]<<endl;
	for(int i=1;i<=n;++i){
		dfs(i);
		for(int j=1;j<=n;++j)vis[j]=0;
	}
	for(int i=1;i<=n;++i){
//		cerr<<i<<": "<<mat[i]-n<<endl;
		if(!mat[i])DFS(i);
	}
	cout<<n-ans<<endl;
	for(int i=1;i<=n;++i){
		if(vis[i]&&(!vis[i+n])) cout<<i<<" ";
	}
	return 0;
}