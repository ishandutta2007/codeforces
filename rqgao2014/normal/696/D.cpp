#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf=1ll<<60;
struct matrix{
	ll a[205][205];
}b;
char s[205][205];
int n,a[205][26],m,next[205],tag[205],val[205],root;
ll l;
queue<int> q;
inline matrix operator * (matrix a,matrix b){
	matrix tmp;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++){
			tmp.a[i][j]=-inf;
			for(int k=0;k<=m;k++)
				tmp.a[i][j]=max(tmp.a[i][j],a.a[i][k]+b.a[k][j]);
		}
	return tmp;
}
void trie(){
	root=0;
	for(int i=1;i<=n;i++){
		int now=root;
		if(!val[i]) continue;
		for(int j=1;j<=strlen(s[i]+1);j++){
			int c=s[i][j]-'a';
			if(!a[now][c]) a[now][c]=++m;
			now=a[now][c];
		}
		tag[now]+=val[i];
	}
}
void build(){
	q.push(root);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<26;i++)
			if(a[x][i]){
				int p=next[x];
				while(p&&!a[p][i]) p=next[p];
				if(a[p][i]) p=a[p][i];
				if(!x) next[a[x][i]]=0; else next[a[x][i]]=p;
				q.push(a[x][i]);
			}
	}
}
inline matrix exp(matrix x,ll y){
	matrix ans;
	memset(ans.a,0,sizeof(ans.a));
	while(y){
		if(y&1) ans=x*ans;
		x=x*x;y>>=1;
	}return ans;
}

int main(){
	scanf("%d%lld",&n,&l);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	trie();build();
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			b.a[i][j]=-inf;
//	printf("%d\n",m);
//	for(int i=0;i<=m;i++) printf("%d ",next[i]);puts("");
	for(int i=0;i<=m;i++)
		for(int c=0;c<26;c++){
			int p=i;ll tmp=0;
			while(p&&!a[p][c]) p=next[p];
			if(a[p][c]) p=a[p][c];
			int t=p;
			while(t) tmp+=tag[t],t=next[t];
			b.a[i][p]=max(b.a[i][p],tmp);
//			if(i==0) printf("%d %lld ",p,tmp);
		}//puts("");
/*	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++) printf("%lld ",b.a[i][j]);
		puts("");
	}*/
	b=exp(b,l);
	ll ans=0;
	for(int i=0;i<=m;i++) ans=max(ans,b.a[0][i]);
	printf("%lld\n",ans);
	return 0;
}
/*
3 6
9 2 3
abc
ab
eeeeee
*/