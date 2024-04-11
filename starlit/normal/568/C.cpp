#include<bits/stdc++.h>
const int N=403;
using namespace std;
int L,n,m,al,pr1,pr2,cnt,lim,
dfn[N],low[N],scc[N],st[N],t;
bool ini[N][N],mp[N][N],ins[N];
int u,v;
char T[30],S[N],inp[3],ans[N];
void dfs(int x){
	dfn[x]=low[x]=++cnt;
	st[t++]=x,ins[x]=1;
	for(int i=2;i<lim;i++)
	if(mp[x][i])
	if(!dfn[i])dfs(i),low[x]=min(low[x],low[i]);
	else if(ins[i])low[x]=min(low[x],dfn[i]);
	if(dfn[x]==low[x])
	for(;st[t]^x;)
	scc[st[--t]]=x,ins[st[t]]=0;
}
inline bool chk(){/*
	for(int i=2;i<lim;i++)
	for(int j=2;j<lim;j++)
	if(mp[i][j])cerr<<"("<<(i>>1)<<','<<(i&1)<<")("<<(j>>1)<<","<<(j&1)<<")\n";
	cerr<<endl;*/
	for(int i=2;i<lim;i++)
	dfn[i]=0;
	for(int i=2;i<lim;i++)
	if(!dfn[i])dfs(i);
	for(int i=1;i<=n;i++)
	if(scc[i<<1]==scc[i<<1|1])return 0;
	return 1;
}
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%s%d%d",T,&n,&m);
	lim=n+1<<1;
	L=strlen(T);
	for(pr1=0;pr1<L&&T[pr1]=='C';pr1++);
	for(pr2=0;pr2<L&&T[pr2]=='V';pr2++);
	for(int i=2;i<=n<<1;i+=2)
	ini[i][i|1]=pr1==L,ini[i|1][i]=pr2==L;
	for(;m--;){
		scanf("%d%s%d",&u,inp,&v);
		u=u<<1|(inp[0]=='C');
		scanf("%s",inp),v=v<<1|(inp[0]=='C');
		ini[u][v]=ini[v^1][u^1]=1;
	}/*
	for(int i=2;i<lim;i++)
	for(int j=2;j<lim;j++)
	if(ini[i][j])cerr<<"("<<(i>>1)<<','<<(i&1)<<")("<<(j>>1)<<","<<(j&1)<<")\n";
	cerr<<"ini completed\n";*/
	scanf("%s",S+1);
	//cerr<<"begin "<<pr1<<','<<pr2<<endl;
	for(al=n;~al;al--){
		//cerr<<"chk al:"<<al<<endl;
		memcpy(mp,ini,sizeof mp);
		for(int i=1;i<=al;i++){
			v=T[S[i]-'a']=='V';
			mp[i<<1|v][(i<<1|1)^v]=1;
		}
		if(al<n){
			for(u=S[al+1]-'a'+1;u<L&&T[u]=='C';u++);
			for(v=S[al+1]-'a'+1;v<L&&T[v]=='V';v++);
			//cerr<<"first V:"<<u<<','<<"first C:"<<v<<endl;
			if(u==L)mp[al+1<<1][al+1<<1|1]=1;
			if(v==L)mp[al+1<<1|1][al+1<<1]=1;
		}
		if(chk())break;
	}
	if(al<0)return puts("-1"),0;
	for(int i=1;i<=al;i++)ans[i]=S[i];
	for(int i=al+1;i<=n;i++){
		if(i>al+1)u=pr1,v=pr2;
		memcpy(mp,ini,sizeof mp);
		if(u>v)swap(u,v);
		ans[i]=u+'a';
		for(int j=1;j<=i;j++){
			if(T[ans[j]-'a']^'C')mp[j<<1|1][j<<1]=1;
			else mp[j<<1][j<<1|1]=1;
		}
		if(!chk())ans[i]=v+'a';
	}
	printf("%s",ans+1);
}