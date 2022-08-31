#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
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

const int N = 4e5+10;
int n1,n2,m,q;
pa e[N];

const int mod = 998244353;
int pw[N];
inline void upd(int &x,int y){
	x+=y;
	if (x>=mod) x-=mod;
}
inline void init(int n){
	pw[0]=1;
	For(i,1,n) pw[i]=2ll*pw[i-1]%mod;
}

int cnt,fa[N],wb[N],dep[N],siz[N],s[N][2],h;
inline void NewNode(){
	++cnt,fa[cnt]=cnt,wb[cnt]=cnt,dep[cnt]=0,siz[cnt]=1,s[cnt][0]=pw[cnt];	
}
inline int Find(int x){
	if (x==fa[x]) return x;
	int tmp=fa[x];
	fa[x]=Find(fa[x]);
	dep[x]^=dep[tmp];
	return fa[x];
}
inline int rev(int x){
	int y=wb[x];
	fa[y]=y,wb[y]=x,dep[y]=0,siz[y]=siz[x],s[y][0]=s[x][0],s[y][1]=s[x][1];
	fa[x]=y;
	if (!(siz[y]&1)){
		dep[x]=1;
		upd(h,mod-s[y][1]),upd(h,s[y][0]);
		swap(s[y][0],s[y][1]);
	}
	return y;
}
inline void Merge(int x,int y){
	int rtx=Find(x),rty=Find(y);
	if (rtx==rty) return;
	int sz=siz[rtx];
	if (rtx==x) rtx=rev(rtx);
	if (rty!=y) wb[rty]=rty;
	if (rty==y||(siz[rty]&1)){
		dep[rty]=(sz&1);
	} else {
		dep[rty]=(sz&1)^1;
		swap(s[rty][0],s[rty][1]);
		upd(h,mod-s[rty][0]),upd(h,s[rty][1]);
	}
	fa[rty]=rtx,siz[rtx]+=siz[rty],wb[rtx]=wb[rty];
	if ((sz&1)){
		upd(h,mod-s[rty][1]),upd(h,s[rty][0]);
		upd(s[rtx][0],s[rty][1]),upd(s[rtx][1],s[rty][0]);
	} else {
		upd(s[rtx][0],s[rty][0]),upd(s[rtx][1],s[rty][1]);
	}
}

int tmp1[N],tmp2[N],d1[N],d2[N],f1[N],f2[N],D1[N],D2[N];
inline void Print(){
	poly ret;
	int x=0;
	For(i,1,n1) tmp1[i]=0;
	For(i,1,n2) tmp2[i]=0; 
	For(i,1,cnt){
		Find(i);
		if (dep[i]&1) ret.pb(i),upd(x,pw[i]),tmp1[e[i].fi]++,tmp2[e[i].se]++;
	}
	printf("%d ",siz(ret));
	for (auto i:ret) printf("%d ",i);
	puts("");
	if (!(x==h)) puts("?? 1");
	For(i,1,n1) if (!(abs(D1[i]-2*tmp1[i])==d1[i])) puts("?? 2");
	For(i,1,n2) if (!(abs(D2[i]-2*tmp2[i])==d2[i])) puts("?? 3");
}

inline void Add(int x,int y){
	NewNode();
	if ((d1[x]&1)&&(d2[y]&1)){
		Merge(cnt,f2[y]),Merge(f1[x],cnt),f1[x]=f2[y]=0;
	} else if ((d1[x]&1)&&!(d2[y]&1)){
		Merge(cnt,f1[x]),f1[x]=0,f2[y]=cnt;
	} else if (!(d1[x]&1)&&(d2[y]&1)){
		Merge(cnt,f2[y]),f2[y]=0,f1[x]=cnt;
	} else {
		f1[x]=f2[y]=cnt;
	}
	d1[x]^=1,d2[y]^=1,D1[x]++,D2[y]++;
}

int main(){
	init(4e5);
	n1=read(),n2=read(),m=read();
	For(i,1,m){
		int x=read(),y=read();
		Add(x,y),e[cnt]=mp(x,y);
	}
	q=read();
	while (q--){
		int op=read();
		if (op==1){
			int x=read(),y=read();
			Add(x,y);
			e[cnt]=mp(x,y);
			printf("%d\n",h);
		} else {
			Print();
		}
		fflush(stdout);
	}
}