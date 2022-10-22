#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<stack>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,q;
int tot,last;
char str[200010];
int len[400010],fa[400010],map[400010][27];
vector<int>vec[400010],xvec[400010];
int id[400010];
int dfn[800010],dep[800010];
int idx;
int minn[1000010][22],pos[1000010][22];
int a[200010],b[200010],c[400010];
int siz1[400010],siz2[400010];
long long sum[400010];
long long ans;
int stk[400010];
int top;
void insert(int x,int dx){
	int p=last;
	len[++tot]=len[last]+1;
	id[dx]=tot;
	last=tot;
	while(!map[p][x]&&p>0) map[p][x]=tot,p=fa[p];
	if(!p){
		fa[tot]=1;return ;
	}
	int q=map[p][x];
	if(len[q]==len[p]+1) fa[tot]=q;
	else{
		len[++tot]=len[p]+1;
		for(int i=1;i<=26;++i) map[tot][i]=map[q][i];
		fa[tot]=fa[q],fa[q]=tot;
		fa[last]=tot;
		for(int i=p;map[i][x]==q;i=fa[i]) map[i][x]=tot;
	}
}
void dfs(int x){
	dfn[x]=++idx;
	dep[x]=dep[fa[x]]+1;
//	printf("X:%d,fa:%d,dep:%d\n",x,fa[x],dep[x]);
	minn[idx][0]=dep[x],pos[idx][0]=x;
	for(int v:vec[x]){
		dfs(v);
		minn[++idx][0]=dep[x],pos[idx][0]=x;
	}
}
int query(int l,int r){
	if(l>r) swap(l,r);
	int k=log2(r-l+1);
	if(minn[l][k]<=minn[r-(1<<k)+1][k]) return pos[l][k];
	else return pos[r-(1<<k)+1][k];
}
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}

void doit(int x){
//	printf("x;:%d\n",x);
	xvec[x].clear();
	siz1[x]=siz2[x]=sum[x]=0;
//	if(top==1){
//		stk[++top]=x;return ;
//	}
	int p=query(dfn[stk[top]],dfn[x]);
//	printf("p:%d\n",p);
	if(p==stk[top]){
		stk[++top]=x;return ;
	}
	while(top>1&&dfn[stk[top-1]]>=dfn[p]) xvec[stk[top-1]].pb(stk[top]),--top;
	if(p!=stk[top]){
		siz1[p]=siz2[p]=sum[p]=0;
		xvec[p].clear();
		xvec[p].pb(stk[top]);
		stk[top]=p;
	}
	stk[++top]=x;
}
void xdfs(int x){
//	printf("x:%d\n",x);
	long long tmp=0;
	for(int v:xvec[x]){
		xdfs(v);
		siz1[x]+=siz1[v];
		siz2[x]+=siz2[v];
		tmp+=sum[v];
	}
	sum[x]=1ll*siz1[x]*siz2[x];
	ans+=1ll*(sum[x]-tmp)*len[x];
//	printf("len:%d\n",len[x]);
//	printf("x:%d,siz1:%d,siz2:%d,sum:%d,ans:%lld\n",x,siz1[x],siz2[x],sum[x],ans);
}
int main(){
	tot=last=1;
	n=read(),q=read();
	scanf("%s",str+1);
	for(int i=n;i>=1;--i) insert(str[i]-'a'+1,i);
//	printf("43");
	for(int i=2;i<=tot;++i) vec[fa[i]].pb(i);
//	printf("tot:%d\n",tot);
//	for(int i=1;i<=tot;++i) printf("%d ",fa[i]);
//	printf("\n");
	dfs(1);
	for(int j=1;j<=19;++j){
		for(int i=1;i+(1<<j)-1<=idx;++i){
			if(minn[i][j-1]>minn[i+(1<<j-1)][j-1]){
				minn[i][j]=minn[i+(1<<j-1)][j-1];
				pos[i][j]=pos[i+(1<<j-1)][j-1];
			}
			else{
				minn[i][j]=minn[i][j-1];
				pos[i][j]=pos[i][j-1];
			}
		}
	}
	while(q--){
		int k=read(),l=read();
		for(int i=1;i<=k;++i) a[i]=id[read()],c[i]=a[i];
		for(int i=1;i<=l;++i) b[i]=id[read()],c[i+k]=b[i];
		sort(c+1,c+k+l+1);
		int m=unique(c+1,c+k+l+1)-c-1;
		sort(c+1,c+m+1,cmp);
//		printf("m:%d\n",m);
		top=0;
		xvec[c[1]].clear();siz1[c[1]]=siz2[c[1]]=sum[c[1]]=0;
		stk[++top]=c[1];
		for(int i=2;i<=m;++i){
			doit(c[i]);
		}
        while(top>1)  xvec[stk[top-1]].pb(stk[top]),--top;
        ans=0;
        for(int i=1;i<=k;++i) siz1[a[i]]=1;
        for(int i=1;i<=l;++i) siz2[b[i]]=1;
        xdfs(stk[top]);
        printf("%lld\n",ans);
	}
}