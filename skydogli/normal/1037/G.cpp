#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define MN 100005
char ch[MN];
int f[MN][27],g[MN];
int nxt[MN][26],lst[MN][26];
int MEX[27];
int n,l,r,len; 
int work(int l,int r,int col,int op){
	if(l>r)return 0;
	if(MEX[col]>=0)return MEX[col];
	int vis[31];memset(vis,0,sizeof(vis));
	for(int i=0;i<26;++i){
		int _l=nxt[l][i],_r=lst[r][i];
		if(_r>=l){
			int v=g[_r]^g[_l]^(!op?f[_l-1][col]:work(l,_l-1,i,1))^(op?f[r][i]:work(_r+1,r,i,0));
			vis[v]=1;
		}
	}
	for(int i=0;i<=26;++i)if(!vis[i]){
		return MEX[col]=i;
	}
}
int main(){
	scanf("%s",ch+1);
	len=strlen(ch+1);
	for(int i=1;i<=len;++i){
		for(int j=0;j<26;++j)
			lst[i][j]=lst[i-1][j];
		lst[i][ch[i]-'a']=i;
	}
	for(int j=0;j<26;++j)nxt[len+1][j]=len+1;
	for(int i=len;i;--i){
		for(int j=0;j<26;++j)
			nxt[i][j]=nxt[i+1][j];
		nxt[i][ch[i]-'a']=i;
	}
	for(int i=1;i<=len;++i){
		g[i]=g[lst[i-1][ch[i]-'a']]^f[i-1][ch[i]-'a'];
		memset(MEX,-1,sizeof(MEX));
		for(int j=0;j<26;++j){
			f[i][j]=work(lst[i][j]+1,i,j,0);
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&l,&r);
		memset(MEX,-1,sizeof(MEX));
		puts(work(l,r,26,1)!=0?"Alice":"Bob");
	}
	return 0;
}