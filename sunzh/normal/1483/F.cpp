#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
int n;
string s[1000010];
int cnt=0;
int tr[1000010][26];
int fail[1000010];vector<int>vec[1000010];
int pos[1000010],id[1000010];
void getfail(){
	queue<int>q;
	for(int i=0;i<26;++i) if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty()){
		int u=q.front();q.pop();
		// printf("u:%d\n",u);
		for(int i=0;i<26;++i)if(tr[u][i]){
			// printf("%d ",tr[u][i]);
			fail[tr[u][i]]=tr[fail[u]][i];q.push(tr[u][i]);
		}
		else tr[u][i]=tr[fail[u]][i];
		// printf("\n");
	}
	// for(int i=1;i<=cnt;++i) printf("%d %d\n",fail[i],i);
	for(int i=1;i<=cnt;++i) vec[fail[i]].pb(i);
}
int dfn[1000010],siz[1000010],idx;
void dfs(int x){
	dfn[x]=++idx;siz[x]=1;
	for(int v:vec[x]){
		if(!id[v]) id[v]=id[x];
		dfs(v);
		siz[x]+=siz[v];
	}
}
int Cnt[1000010];
int Id[1000010];
int tre[1000010];
void upd(int x,int k){
	while(x<=idx) tre[x]+=k,x+=x&-x;
}
int query(int x){
	int res=0;while(x)res+=tre[x],x-=x&-x;
	return res;
}
int qry(int l,int r){return query(r)-query(l-1);}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		int p=0;
		for(int j=0;j<s[i].size();++j){
			if(!tr[p][s[i][j]-'a']) tr[p][s[i][j]-'a']=++cnt;
			p=tr[p][s[i][j]-'a'];
		}
		pos[i]=p;id[p]=i;
		// printf("i:%d,p:%d\n",i,p);
	}
	getfail();dfs(0);
	long long ans=0;
	for(int i=1;i<=n;++i){
		int tmp=s[i].size()+1;
		int p=0;
		set<int>st;
		for(int j=0;j<s[i].size();++j){
			p=tr[p][s[i][j]-'a'];upd(dfn[p],1);
			if(j==s[i].size()-1) p=fail[p];
			if(id[p]) Id[j]=id[p],st.insert(Id[j]);else Id[j]=-1;
			// printf("p:%d\n",p);
		}
		// for(int j:st) printf("%d ",j);printf("\n");
		for(int j=s[i].size()-1;j>=0;--j){
			if(Id[j]!=-1&&(j-s[Id[j]].size()+1)<tmp) tmp=j-s[Id[j]].size()+1,++Cnt[Id[j]];
		}
		for(int j:st){
			// printf("j:%d,%d,%d\n",j,Cnt[j],qry(dfn[pos[j]],dfn[pos[j]]+siz[pos[j]]-1));
			if(Cnt[j]==qry(dfn[pos[j]],dfn[pos[j]]+siz[pos[j]]-1)) ++ans;
		}

		tmp=s[i].size()+1;
		p=0;
		for(int j=0;j<s[i].size();++j){
			p=tr[p][s[i][j]-'a'];upd(dfn[p],-1);
			// if(j==s[i].size()-1) p=fail[p];
			Cnt[Id[j]]=0;
		}
	}
	printf("%lld\n",ans);
}