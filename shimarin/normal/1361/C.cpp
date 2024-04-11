//
#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) cout<<#v<<":";for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 4e6+10;
int n,a[N],b[N],v[N],p[N];
pa c[N],e[N];

struct Graph{
	int n,m;
	int head[N],nxt[N],v[N],id[N],tot=0;
	int que[N],d[N],g[N],cnt=0;
	bool vis[N];
	inline void init(int _n){
		n=_n,m=cnt=tot=0;
		For(i,1,n) head[i]=0,d[i]=g[i]=0;
	}
	inline int abs(int p){
		return p<0?-p:p;
	}
	inline void add(int a,int b,int val){
		d[a]++,g[b]++;
		tot++,nxt[tot]=head[a],head[a]=tot,v[tot]=b,id[tot]=val;
	}
	inline void Add(int a,int b){
		++m,vis[m]=0;
		add(a,b,m),add(b,a,-m);
	}
	inline void dfs(int pos){
		for (int i=head[pos];i;i=head[pos]){
			head[pos]=nxt[i];
			if (!vis[abs(id[i])]){
				vis[abs(id[i])]=1;
				dfs(v[i]);
				que[++cnt]=id[i];
			}
		}
	}
	inline vector<int> Find(){
		For(i,1,n) if (d[i]&1) return {0};
		For(i,1,n){
			if (d[i]||g[i]){
				dfs(i);break;
			}
		}
		if (cnt!=m) return {0};
		vector<int> ans={1};
		Dow(i,cnt,1) ans.pb(que[i]);
		return ans;
	}
}G;

int main(){
	n=read();
	int tot=0;
	For(i,1,n) a[i]=read(),b[i]=read(),v[++tot]=a[i],v[++tot]=b[i];
	vector<int>Ans,ans;
	For(i,1,2*n) ans.pb(i); 
	For(i,1,20){
		int cnt=0;
		For(j,1,tot) c[++cnt]=mp(v[j]&((1<<i)-1),j);
		sort(c+1,c+1+cnt);
		int tot=0;
		for (int l=1,r=1;l<=cnt;l=++r){
			while (r<cnt&&c[r+1].fi==c[r].fi) ++r;
			++tot;
			For(j,l,r) p[c[j].se]=tot;
		}
		G.init(tot);
		For(j,1,n){
			G.Add(p[j*2-1],p[j*2]),e[j]=mp(j*2-1,j*2);
	//		if (i==2) printf("2333 %d %d\n",p[j*2-1],p[j*2]);
		}
		Ans=G.Find();
	//	if (i==2){
	//		for (auto j:Ans) printf("%d ",j);puts("");
	//	}
		if (!Ans[0]){
			printf("%d\n",i-1);
			for (auto i:ans) printf("%d ",i);
			return 0;
		} else {
			ans.clear();
			FOR(i,1,siz(Ans)) 
				if (Ans[i]>0) ans.pb(e[Ans[i]].fi),ans.pb(e[Ans[i]].se);
					else ans.pb(e[-Ans[i]].se),ans.pb(e[-Ans[i]].fi);
			//for (int j=2;j<siz(ans);j+=2){
				//if (j==6) printf("23333 %d %d\n",v[ans[j-1]],v[ans[j]]);
			//	if ((v[ans[j-1]]&((1<<i)-1))!=(v[ans[j]]&((1<<i)-1))) swap(ans[j],ans[j+1]);
			//}
		}
	}
	printf("%d\n",20);
	FOR(i,0,siz(ans)) printf("%d ",ans[i]);
}