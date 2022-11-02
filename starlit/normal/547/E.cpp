#include<bits/stdc++.h>
const int N=500005;
using namespace std;
typedef long long ll;
int n,m,al,fr[N],re[N],hd[N],lk[N],
le,p,q,r,s,f[N],ln[N],c[N][26],cnt=1,
dl[N],dr[N],b[N];
ll ans[N],tp;
char S[N];
struct dat{
	int l,k,no;
}a[N*2];
inline void ext(int tr,int d){
	if(c[p][tr])s=0;
	else ln[s=++cnt]=d;
	for(;p&&!c[p][tr];p=f[p])c[p][tr]=s;
	if(q=c[p][tr]){
		if(ln[q]>ln[p]+1){
			f[r=++cnt]=f[q],ln[r]=ln[p]+1;
			f[q]=r,s?f[s]=r:s=r;
			for(int i=0;i<26;i++)
			c[r][i]=c[q][i];
			for(;c[p][tr]==q;p=f[p])c[p][tr]=r;
		}
		else s?f[s]=q:s=q;
	}else f[s]=1;
	p=s;
}
void dfs(int x){
	dl[x]=cnt++;
	//cerr<<"dfn "<<x<<":"<<cnt<<endl;
	for(int i=lk[x];i;i=hd[i])dfs(i);
	dr[x]=cnt;
}
inline void ins(int x){
	//cerr<<"ins "<<x<<endl;
	for(;x<=n;x+=x&-x)b[x]++;
}
inline ll qry(int x){
	//cerr<<"qry "<<x<<endl;
	ll y=0;
	for(;x;x-=x&-x)y+=b[x];
	return y;
}
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",S);
		p=1,le=strlen(S),fr[i]=al;
		for(int j=0;j<le;j++)
		ext(S[j]-'a',j+1),//cerr<<p<<' ',
		re[al++]=p;
		cerr<<endl;
	}fr[n+1]=al;
	for(int i=2;i<=cnt;i++)
	//cerr<<"f["<<i<<"]"<<f[i]<<endl,
	hd[i]=lk[f[i]],lk[f[i]]=i;
	n=cnt,cnt=0,dfs(1);
	cnt=0;
	for(int i=1;i<=m;i++)
	scanf("%d%d%d",&p,&q,&s),
	a[cnt++]={q,s,i},a[cnt++]={p-1,s,-i};
	sort(a,a+cnt,[](dat x,dat y){
		return x.l<y.l;
	});
	for(int i=0,j=0;i<cnt;i++){
		//cerr<<"Qry "<<a[i].l<<','<<a[i].k<<endl;
		for(;j<a[i].l;)
		for(int k=fr[++j];k<fr[j+1];k++)
		ins(dl[re[k]]+1);
		s=re[fr[a[i].k+1]-1];
		tp=qry(dr[s])-qry(dl[s]);
		p=a[i].no;
		if(p<0)ans[-p]-=tp;else ans[p]+=tp;
		//cerr<<"~"<<tp<<endl;
	}
	for(int i=1;i<=m;i++)
	printf("%lld\n",ans[i]);
}