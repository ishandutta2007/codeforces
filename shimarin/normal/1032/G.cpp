#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cerr<<i<<" ";puts("")
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
int n,a[N],l[N][17],r[N][17];

pa v[17][N<<2];
inline pa operator + (const pa &a,const pa &b){
	return mp(min(a.fi,b.fi),max(a.se,b.se));
}
inline void Build(int k,int u,int l,int r){
	if (l==r) return v[k][u]=mp(::l[l][k],::r[l][k]),void(0);
	int mid=l+r>>1;
	Build(k,u<<1,l,mid),Build(k,u<<1^1,mid+1,r);
	v[k][u]=v[k][u<<1]+v[k][u<<1^1];
}
inline pa Query(int k,int u,int l,int r,int ql,int qr){
	if (l>=ql&&r<=qr) return v[k][u];
	int mid=l+r>>1;
	if (qr<=mid) return Query(k,u<<1,l,mid,ql,qr);
	if (ql>mid) return Query(k,u<<1^1,mid+1,r,ql,qr);
	return Query(k,u<<1,l,mid,ql,qr)+Query(k,u<<1^1,mid+1,r,ql,qr);
}

int main(){
	n=read();
	For(i,1,n) a[i]=read();
	For(i,n+1,3*n) a[i]=a[i-n];	
	For(i,1,3*n) l[i][0]=max(1,i-a[i]),r[i][0]=min(3*n,i+a[i]);
	Build(0,1,1,3*n);
	For(j,1,16){
		For(i,1,3*n){
			pa tmp=Query(j-1,1,1,3*n,l[i][j-1],r[i][j-1]);
			l[i][j]=tmp.fi,r[i][j]=tmp.se;
		}
		Build(j,1,1,3*n);
	}
	if (n==1) return puts("0"),0;
	For(i,n+1,2*n){
		int l=i,r=i,ans=0;
		Dow(j,16,0){
			pa tmp=Query(j,1,1,3*n,l,r);
			if (tmp.se-tmp.fi+1<n) l=tmp.fi,r=tmp.se,ans+=1<<j;
		}
		printf("%d ",ans+1);
	}
}