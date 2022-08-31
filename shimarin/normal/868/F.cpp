//wit studio
#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
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
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 1e5+10, K = 21;
int n,k,a[N];
ll f[K][N];

int L,R,cnt[N];
ll sum;
inline void Add(int x){
	sum+=cnt[a[x]]++;
}
inline void Del(int x){
	sum-=--cnt[a[x]];
}
inline void F(int l,int r){
	while (L>l) Add(--L);
	while (R<r) Add(++R);
	while (L<l) Del(L++);
	while (R>r) Del(R--);
}
inline void solve(int k,int l,int r,int L,int R){
	if (l>r) return;
	int mid=l+r>>1,Mid=0;
	For(i,L,min(R,mid-1)){
		F(i+1,mid);
		if (f[k-1][i]+sum<f[k][mid]) f[k][mid]=f[k-1][i]+sum,Mid=i;
	}
	solve(k,l,mid-1,L,Mid),solve(k,mid+1,r,Mid,R);
}

int main(){
	n=read(),k=read();
	For(i,1,n) a[i]=read();
	For(i,0,k) For(j,0,n) f[i][j]=1e15;
	f[0][0]=0,L=1;
	For(i,1,k) solve(i,1,n,0,n);
	printf("%lld\n",f[k][n]);
}