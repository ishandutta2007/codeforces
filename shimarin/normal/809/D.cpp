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

const int N = 3e5+10;
int n,l[N],r[N];

int cnt,rt,v[N],tag[N],lson[N],rson[N],siz[N],w[N];
inline int Newnode(int x){
	v[++cnt]=x,siz[cnt]=1,w[cnt]=rand();
	return cnt;
}
inline void upd(int u,int x){
	if (u) tag[u]+=x,v[u]+=x;
}
inline void push_down(int u){
	if (tag[u]) upd(lson[u],tag[u]),upd(rson[u],tag[u]),tag[u]=0;
}
inline void push_up(int u){
	siz[u]=siz[lson[u]]+siz[rson[u]]+1;
}
inline void Split(int u,int &x,int &y,int k){
	if (!u) return x=y=0,void(0);
	push_down(u);
	if (v[u]<=k) x=u,Split(rson[u],rson[u],y,k);
		else y=u,Split(lson[u],x,lson[u],k);
	push_up(u);
}
inline int Merge(int x,int y){
	if (!x||!y) return x^y;
	push_down(x),push_down(y);
	if (w[x]<w[y]){
		rson[x]=Merge(rson[x],y);
		return push_up(x),x;
	} else {
		lson[y]=Merge(x,lson[y]);
		return push_up(y),y;
	}
}
inline void Print(int u){
	if (lson[u]) Print(lson[u]);
	push_down(u),printf("%d ",v[u]);
	if (rson[u]) Print(rson[u]);
}
inline int insert(int x){
	int a,b;
	Split(rt,a,b,x);
	int tmp=a;push_down(tmp);
	while (rson[tmp]) push_down(tmp),tmp=rson[tmp];
	if (v[tmp]==x) return rt=Merge(a,b),0;
	int c=Newnode(x);
	rt=Merge(Merge(a,c),b);
	return 1;
}
inline void erase(int x){
	int a,b,c;
	Split(rt,a,b,x-1);
	int tmp=b;
	while (lson[tmp]) push_down(tmp),tmp=lson[tmp];
	Split(b,b,c,v[tmp]);
	rt=Merge(a,c);
}
inline void update(int l,int r){
	if (l>r) return;
	int a,b,c;
	Split(rt,a,b,l-1);
	Split(b,b,c,r);
	upd(b,1);
	rt=Merge(Merge(a,b),c);
}

int main(){
	n=read();
	For(i,1,n) l[i]=read(),r[i]=read();
	For(i,1,n){
		erase(r[i]);
		if (insert(l[i])){
			update(l[i]+1,r[i]);
		} else {
			update(l[i],r[i]);
			insert(l[i]);
		}
	}
	printf("%d\n",siz[rt]);
}