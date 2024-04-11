#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct qry{
	int id,fa,x;
	char ch;
}q[100000];
struct nod{
	int ch[26],ct,mp;
	nod(){
		for(int i=0;i<26;i++)ch[i]=-1;
		ct=0;mp=-1;
	}
}cr[100100];
const long long M=2000000063LL,R=1629629681LL;
vector<int> tt[100100],tc[100100];
vector<pair<long long,int> > hp;
long long hsh[100000],pw[100000],rv[100000],tr[400400],tg[400400],ct[100100],ans[100100];
int sz[100100],fd[100100],fa[100100][17],fa1[100000],tot=0,lst[100100],rt[100100];
int m1=1,m2=1,dp[100100],dep[100100],dfn[100100],fnd[100100],cnt=1,org[100100];
void dfs(int x,long long h){
	h%=M;
	sz[x]=1;
	hp.push_back(make_pair(h,x));
	for(int i=0;i<26;i++)if(cr[x].ch[i]!=-1){
		dp[cr[x].ch[i]]=dp[x]+1;
		dfs(cr[x].ch[i],h*27+i+1);
		sz[x]+=sz[cr[x].ch[i]];
		if(cr[x].mp==-1 || sz[cr[x].mp]<sz[cr[x].ch[i]])cr[x].mp=cr[x].ch[i];
		fa1[cr[x].ch[i]]=x;
	}
}
void dfs1(int x){
	for(int i=0;i<tt[x].size();i++){
		dep[tt[x][i]]=dep[x]+1;
		hsh[tt[x][i]]=(tc[x][i]-'a'+1)*pw[dep[x]]+hsh[x];
		hsh[tt[x][i]]%=M;
		dfs1(tt[x][i]);
	}
}
void mpt(int x){
	org[tot]=x;
	dfn[x]=tot++;
	if(cr[x].mp==-1)return;
	rt[cr[x].mp]=rt[x];
	mpt(cr[x].mp);
	for(int i=0;i<26;i++)if(cr[x].ch[i]!=cr[x].mp && cr[x].ch[i]!=-1){
		rt[cr[x].ch[i]]=cr[x].ch[i];
		mpt(cr[x].ch[i]);
	}
}
void add(int x,int t){
	while(x<=tot){
		ct[x]+=t;
		x+=(x&-x);
	}
}
long long query(int x){
	long long ans=0;
	while(x){
		ans+=ct[x];
		x-=(x&-x);
	}
	return ans;
}
void push_down(int i,int l,int r){
	if(tg[i]==0)return;
	int mid=(l+r)>>1;
	tr[i*2]+=tg[i]*(query(mid)-query(l));
	tg[i*2]+=tg[i];
	tr[i*2+1]+=tg[i]*(query(r)-query(mid));
	tg[i*2+1]+=tg[i];
	tg[i]=0;
}
void push_up(int i){
	tr[i]=tr[i*2]+tr[i*2+1];
}
void add(int i,int l,int r,int l0,int r0,int w){
	if(l>=l0 && r<=r0){
		tr[i]+=w*(query(r)-query(l));
		tg[i]+=w;
		return;
	}
	push_down(i,l,r);
	int mid=(l+r)>>1;
	if(mid>l0)add(i*2,l,mid,l0,r0,w);
	if(mid<r0)add(i*2+1,mid,r,l0,r0,w);
	push_up(i);
}
void add(int i,int l,int r,int x,int w){
	if(r-l==1){
		tr[i]+=w;
		return;
	}
	push_down(i,l,r);
	int mid=(l+r)>>1;
	if(mid>x)add(i*2,l,mid,x,w);else add(i*2+1,mid,r,x,w);
	push_up(i);
}
long long query(int i,int l,int r,int x){
	if(r-l==1)
		return tr[i];
	push_down(i,l,r);
	int mid=(l+r)>>1;
	if(mid>x)return query(i*2,l,mid,x);else return query(i*2+1,mid,r,x);
}
int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	int n;scanf("%d",&n);
	pw[0]=1;rv[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*27LL,pw[i]%=M,rv[i]=rv[i-1]*R,rv[i]%=M;
	cr[0].ct=1;
	for(int i=0;i<n;i++){
		char c[10];
		scanf("%d%d%s",&q[i].id,&q[i].fa,c);q[i].fa--;
		q[i].x=(q[i].id==1)?m1++:m2++;
		q[i].ch=c[0];
		if(q[i].id==1){
			q[i].fa=fnd[q[i].fa];
			if(cr[q[i].fa].ch[q[i].ch-'a']==-1){
				cr[q[i].fa].ch[q[i].ch-'a']=q[i].x;
				fnd[q[i].x]=q[i].x;
				cr[cr[q[i].fa].ch[q[i].ch-'a']].ct=1;
			}else{
				cr[cr[q[i].fa].ch[q[i].ch-'a']].ct++;
				fnd[q[i].x]=cr[q[i].fa].ch[q[i].ch-'a'];
			}
		}else{
			tt[q[i].fa].push_back(q[i].x);
			tc[q[i].fa].push_back(q[i].ch);
			fa[q[i].x][0]=q[i].fa;
		}
	}
	fa1[0]=-1;
	dfs(0,0);dfs1(0);
	sort(hp.begin(),hp.end());
	rt[0]=0;mpt(0);
/*	for(int i=0;i<m1;i++)printf("%d ",dfn[i]);printf("\n");
	for(int i=0;i<m1;i++){
		printf("%d\n",cr[i].ct);
		for(int j=0;j<26;j++)if(cr[i].ch[j]!=-1){
			printf("%d ",cr[i].ch[j]);
		}printf("\n");
	}*/
	for(int j=1;j<17;j++)
		for(int i=0;i<m2;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	for(int i=0;i<tot;i++){
		int j=i+1;
		for(int k=0;k<(j&-j);k++){
			ct[j]+=cr[org[i-k]].ct;
		}
	}
//	for(int i=0;i<=tot;i++)printf("%I64d ",ct[i]);printf("\n");
	for(int i=0;i<m2;i++){
//			if(i==17){
//				i=17;
//			}
		int y=i;
		for(int j=16;j>=0;j--){
			int t=fa[y][j];
			long long tmp=(hsh[i]-hsh[t])*rv[dep[t]];tmp%=M;tmp+=M;tmp%=M;
			vector<pair<long long,int> >::iterator it=lower_bound(hp.begin(),hp.end(),make_pair(tmp,-1));
			if(it<hp.end() && it->first==tmp){
				y=t;
				lst[i]=it->second;
			}
		}
//		printf("%d\n",lst[i]);
		int now=lst[i];
		while(now!=-1){
			int t=rt[now];
			add(1,0,tot,dfn[t],dfn[now]+1,1);
			now=fa1[t];
		}
	}
	for(int i=n-1;i>=0;i--){
		ans[i]=tr[1];
		if(q[i].id==1){
			long long t=query(1,0,tot,dfn[fnd[q[i].x]])/(query(dfn[fnd[q[i].x]]+1)-query(dfn[fnd[q[i].x]]));
			add(1,0,tot,dfn[fnd[q[i].x]],-t);
			add(dfn[fnd[q[i].x]]+1,-1);
		}else{
			int now=lst[q[i].x];
			while(now!=-1){
				int t=rt[now];
				add(1,0,tot,dfn[t],dfn[now]+1,-1);
				now=fa1[t];
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%I64d\n",ans[i]);
	return 0;
}