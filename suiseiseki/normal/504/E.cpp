#include <vector>
#include <cstdio>
#include <cctype>
using namespace std;
namespace io {
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
  inline char getc () {return (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++);}
  inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
  inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
  template<class T>
  inline void read(T &x) {
    char ch; int f = 1;
    x = 0;
    while(isspace(ch = getc()));
    if(ch == '-') ch = getc(), f = -1;
    do x = x * 10 + ch - '0'; while(isdigit(ch = getc()));
    x *= f;
  }
  template<class T, class ...Args>
  inline void read(T &x, Args&... args) {read(x); read(args...);}
  template<class T>
  inline void write(T x) {
    static char stk[128];
    int top = 0;
    if(x == 0) {putc('0'); return;}
    if(x < 0) putc('-'), x = -x;
    while(x) stk[top++] = x % 10, x /= 10;
    while(top) putc(stk[--top] + '0');
  }
  template<class T, class ...Args>
  inline void write(T x, Args... args) {write(x); putc(' '); write(args...);}
  inline void space() {putc(' ');}
  inline void endl() {putc('\n');}
  struct _flush {~_flush() {flush();}} __flush;
};
using io::read; using io::write; using io::flush; using io::space; using io::endl; using io::getc; using io::putc;

int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
void add(int &x,int y,int Mod){
	x+=y;
	if(x>=Mod){
		x-=Mod;
	}
}
void del(int &x,int y,int Mod){
	x-=y;
	if(x<0){
		x+=Mod;
	}
}
typedef long long ll;
const int Maxn=300000;
const int Base[2]={107,59},Mod[2]={1004535809,1000000007};
int pow_b[2][Maxn+5],inv_b[2][Maxn+5];
int f[20][Maxn<<1|5];
int log_2[Maxn<<1|5];
int dfn[Maxn+5],rnk[Maxn<<1|5],dfn_tot;
void init(){
	for(register int i=0;i<2;++i){
		pow_b[i][0]=1;
		inv_b[i][0]=1;
		for(int j=1;j<=Maxn;++j){
			pow_b[i][j]=1ll*pow_b[i][j-1]*Base[i]%Mod[i];
			inv_b[i][j]=quick_power(pow_b[i][j],Mod[i]-2,Mod[i]);
		}
	}
	for(register int i=1;(1<<i)<=dfn_tot;++i){
		for(register int j=1;j+(1<<i)-1<=dfn_tot;++j){
			f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
		}
	}
	log_2[1]=0;
	for(register int i=2;i<=(Maxn<<1);++i){
		log_2[i]=log_2[i>>1]+1;
	}
}
char s[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
inline void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int n,m;
int dep[Maxn+5];
int fa[20][Maxn+5],mx_dep[Maxn+5];
int root;
int son[Maxn+5],top[Maxn+5];
void init_dfs_1(int u){
	for(register int i=1;fa[i-1][fa[i-1][u]];++i){
		fa[i][u]=fa[i-1][fa[i-1][u]];
	}
	dep[u]=dep[fa[0][u]]+1;
	mx_dep[u]=1;
	for(register int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[0][u]){
			continue;
		}
		fa[0][v]=u;
		init_dfs_1(v);
		if(mx_dep[v]+1>mx_dep[u]){
			mx_dep[u]=mx_dep[v]+1;
			son[u]=v;
		}
	}
}
vector<int> lis_up[Maxn+5],lis_down[Maxn+5];
void init_dfs_2(int u,int tp){
	lis_down[tp].push_back(u);
	if(u==tp){
		int len=0,tmp=u;
		while(tmp&&len<mx_dep[u]){
			lis_up[u].push_back(tmp);
			tmp=fa[0][tmp];
			len++;
		}
	}
	top[u]=tp;
	if(son[u]){
		init_dfs_2(son[u],tp);
	}
	for(register int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[0][u]||v==son[u]){
			continue;
		}
		init_dfs_2(v,v);
	}
}
inline int find_kth(int u,int k){
	if(k==0){
		return u;
	}
	int tmp=log_2[k];
	int v=fa[tmp][u];
	v=top[v];
	if(dep[v]<=dep[u]-k){
		return lis_down[v][dep[u]-k-dep[v]];
	}
	return lis_up[v][dep[v]-dep[u]+k];
}
inline int find_lca(int u,int v){
	u=dfn[u],v=dfn[v];
	if(u>v){
		swap(u,v);
	}
	int k=log_2[v-u+1];
	return rnk[min(f[k][u],f[k][v-(1<<k)+1])];
}
int num_up[2][Maxn+5],num_down[2][Maxn+5];
void init_dfs_3(int t,int u){
	num_down[t][u]=(1ll*num_down[t][fa[0][u]]*Base[t]+(s[u]-'a'+1))%Mod[t];
	num_up[t][u]=(num_up[t][fa[0][u]]+1ll*pow_b[t][dep[u]-1]*(s[u]-'a'+1))%Mod[t];
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[0][u]){
			continue;
		}
		init_dfs_3(t,v);
	}
}
inline int find_hash(int t,int u,int v){
	int ans=0;
	if(dep[u]>dep[v]){
		ans=num_up[t][u];
		ans=(1ll*ans-num_up[t][fa[0][v]]+Mod[t])%Mod[t];
		ans=1ll*ans*inv_b[t][dep[v]-1]%Mod[t];
	}
	else{
		ans=num_down[t][v];
		ans=(ans-1ll*num_down[t][fa[0][u]]*pow_b[t][dep[v]-dep[u]+1]%Mod[t]+Mod[t])%Mod[t];
	}
	return ans;
}
inline int find_hash(int t,int u,int v,int lca,int k){
	if(dep[u]-dep[lca]>=k){
		return find_hash(t,u,find_kth(u,k));
	}
	int ans;
	if(u==lca){
		ans=0;
	}
	else{
		ans=find_hash(t,u,find_kth(u,dep[u]-dep[lca]-1));
	}
	k=(dep[u]+dep[v]-(dep[lca]<<1))-k;
	int tmp=find_hash(t,lca,find_kth(v,k));
	ans=(1ll*ans*pow_b[t][dep[v]-dep[lca]-k+1]+tmp)%Mod[t];
	return ans;
}
inline int query(int u_1,int v_1,int u_2,int v_2){
	if(s[u_1]!=s[u_2]){
		return 0;
	}
	int lca_1=find_lca(u_1,v_1),lca_2=find_lca(u_2,v_2);
	int len=min(dep[u_1]+dep[v_1]-(dep[lca_1]<<1),dep[u_2]+dep[v_2]-(dep[lca_2]<<1));
	int left=0,right=len;
	while(left<right){
		int mid=(left+right+1)>>1;
		if(find_hash(0,u_1,v_1,lca_1,mid)==find_hash(0,u_2,v_2,lca_2,mid)&&find_hash(1,u_1,v_1,lca_1,mid)==find_hash(1,u_2,v_2,lca_2,mid)){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	return left+1;
}
void init_dfs_4(int u){
	dfn[u]=++dfn_tot;
	f[0][dfn_tot]=dfn[u];
	rnk[dfn_tot]=u;
	for(register int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[0][u]){
			continue;
		}
		init_dfs_4(v);
		f[0][++dfn_tot]=dfn[u];
	}
}
int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	read(n);
	{
		char c=getc();
		while(c<'a'||c>'z'){
			c=getc();
		}
		int len=0;
		while(c>='a'&&c<='z'){
			s[++len]=c;
			c=getc();
		}
	}
	for(register int i=1;i<n;++i){
		int u,v;
		read(u),read(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs_1(1);
	init_dfs_2(1,1);
	init_dfs_4(1);
	init();
	init_dfs_3(0,1);
	init_dfs_3(1,1);
	read(m);
	for(register int i=1;i<=m;++i){
		int u_1,v_1,u_2,v_2;
		read(u_1),read(v_1),read(u_2),read(v_2);
		write(query(u_1,v_1,u_2,v_2));
		putc('\n');
	}
	return 0;
}