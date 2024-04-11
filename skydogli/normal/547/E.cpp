#include<bits/stdc++.h>
using namespace std;
#define mn 200005
#define MN 500005
int cnt=1;
int add[mn][26],fail[mn],siz[mn],id[mn],sum[mn],lst[mn];
char ch[mn];
queue<int>Q;
vector<int>edge[mn];
int Ins(char *ch,int len){
	int now=1;
	for(int i=1;i<=len;++i){
		int to=ch[i]-'a';
		if(!add[now][to])add[now][to]=++cnt;
		lst[add[now][to]]=now;
		now=add[now][to];
	}
//	cerr<<"? "<<now<<endl;
	return now;
}
void getfail(){
	for(int i=0;i<26;++i)if(add[1][i]){
		fail[add[1][i]]=1;Q.push(add[1][i]);
//		cerr<<"FK "<<i<<endl;
	}
	while(!Q.empty()){
		int x=Q.front();Q.pop();
		for(int i=0;i<26;++i)
			if(add[x][i]){
				Q.push(add[x][i]);
				fail[add[x][i]]=add[fail[x]][i];
				if(!fail[add[x][i]])fail[add[x][i]]=1;
			}
			else {
				add[x][i]=add[fail[x]][i];
				if(!add[x][i])add[x][i]=1;
			}
	}
}
void Add(int x){
	while(x<=cnt)sum[x]++,x+=x&(-x);
}
int ask(int x){
	int res=0;
	while(x)res+=sum[x],x-=x&(-x);
	return res;
}
int tot;
void dfs(int x){
	siz[x]=1;
	id[x]=++tot;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(fail[x]==v)continue;
		dfs(v);
		siz[x]+=siz[v];
	}
}
int n,q,pos[MN],l[MN],r[MN],k[MN],ans[MN];
vector<int>qr[MN];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		scanf("%s",ch+1);
		pos[i]=Ins(ch,strlen(ch+1));
	}
	getfail();
	for(int i=2;i<=cnt;++i){
		edge[fail[i]].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=q;++i){
		scanf("%d%d%d",&l[i],&r[i],&k[i]);
		qr[l[i]-1].push_back(i);
		qr[r[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		int p=pos[i];
		while(p!=1){
			Add(id[p]),p=lst[p];
		}
		for(int j=0;j<qr[i].size();++j){
			int ID=qr[i][j],x=pos[k[ID]];
			int tmp=ask(id[x]+siz[x]-1)-ask(id[x]-1);
			if(l[ID]-1==i) ans[ID]-=tmp;
			else ans[ID]+=tmp;
		}
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}