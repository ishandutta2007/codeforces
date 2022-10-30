#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 800100

#define mid (L+R>>1)
#define ls (u<<1)
#define rs (ls | 1)

int mn[NN], ma[NN];
int flag[NN];
INT sum[NN];
int a[NN];

int push_up(int u) {
	sum[u] = sum[ls] + sum[rs];
	ma[u] = max(ma[rs], ma[ls]);
	mn[u] = min(mn[rs], mn[ls]);
}

int update(int u, int L, int R, int x) {
	mn[u] = ma[u] = flag[u] = x;
	sum[u] = (INT) (R - L) * x;
}

int push_down(int u, int L, int R) {
	if(!flag[u]) return 0;
	update(ls, L, mid, flag[u]);
	update(rs, mid, R, flag[u]);
	flag[u] = 0;
	return 0;
}

int build(int u, int L, int R) {
	if(L + 1 == R) {
		ma[u] = mn[u] = sum[u] = L;
		return 0;
	}
	build(ls, L, mid);
	build(rs, mid, R);
	push_up(u);
}

int update(int u, int L, int R, int st, int ed, int x) {
	if(L >= ed || R <= st) return 0;
	
	if(L >= st and R <= ed) {
		if(mn[u] > x) return 0;
		if(ma[u] <= x) return update(u, L, R, x), 0;
	}
	
	push_down(u, L, R);
	
	update(ls, L, mid, st, ed, x);
	update(rs, mid, R, st, ed, x);
	
	push_up(u);
}

vector<int> res[201000];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	gn(n);
	for(int i=1, x; i<=n; i++) {
		gn(x);
		for(int j=1; j*j<=x; j++) if(x % j == 0){
			res[j].push_back(i);
			if(j*j != x) res[x/j].push_back(i);
		}
	}
	
	INT ans = 0;
	build(1, 1, n+1);
	INT pre = sum[1];
	
	for(int i=200000; i; i--) if(res[i].size() > 1) {
		int sz = res[i].size();
		update(1, 1, n+1, res[i][0]+1, res[i][sz-1], res[i][sz-1]);
		update(1, 1, n+1, 1, res[i][sz-2], res[i][sz-2]);
		update(1, 1, n+1, res[i][1] + 1, n + 1, n + 1);
		ans += (sum[1] - pre) * i;
		pre = sum[1];
	}
	
	cout<<ans<<endl;
}