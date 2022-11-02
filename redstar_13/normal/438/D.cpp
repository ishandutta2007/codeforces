#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 100100
int a[NN];
#define ls (u<<1)
#define rs (ls|1)
#define mid (L+R>>1)

int mx[NN<<2];
INT sum[NN<<2];

inline void up(int u){
	mx[u]=max(mx[ls], mx[rs]);
	sum[u]=sum[ls]+sum[rs];
}

void build(int u, int L, int R){
	if(L+1==R){
		mx[u]=sum[u]=a[L];
		return ;
	}
	build(ls, L, mid);
	build(rs, mid, R);
	up(u);
}

void update(int u, int L, int R, int l, int r, int m){
	if(r<=L || R<=l) return ;
	if(mx[u]<m) return ;
	if(L+1==R){
		mx[u]=sum[u]=a[L]%=m;
		return ;
	}
	update(ls, L, mid, l, r, m);
	update(rs, mid, R, l, r, m);
	up(u);
}

void change(int u, int L, int R, int p){
	if(L+1==R){
		mx[u]=sum[u]=a[p];
		return ;
	}
	if(p<mid) change(ls, L, mid, p);
	else change(rs, mid, R, p);
	up(u);
}

INT calc(int u, int L, int R, int l, int r){
	if(r<=L || R<=l) return 0;
	if(l<=L && R<=r) return sum[u];
	return calc(ls, L, mid, l, r)+calc(rs, mid, R, l, r);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) gn(a[i]);
	build(1, 1, n+1);
	
	int tp, l, r, x;
	while(m--){
		gn(tp, l);
		if(tp==1){
			gn(r);
			printf("%I64d\n", calc(1, 1, n+1, l, r+1));
		}
		else if(tp==2){
			gn(r, x);
			update(1, 1, n+1, l, r+1, x);
		}
		else {
			gn(x);
			a[l]=x;
			change(1, 1, n+1, l);
		}
	}
	
	return 0;
}