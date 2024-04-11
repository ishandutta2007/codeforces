#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

#define NN 100010
#define ls (u<<1)
#define rs (ls|1)
#define mid (L+R>>1)

int ma[NN*4], flag[NN*4];
int pos[NN];
int p[NN], t[NN], val[NN];

int push_down(int u) {
	if(!flag[u]) return 0;
	flag[ls] += flag[u], flag[rs] += flag[u];
	ma[ls] += flag[u], ma[rs] += flag[u];
	return flag[u] = 0;
}

int push_up(int u) {
	ma[u] = max(ma[ls], ma[rs]);
	return 0;
}

int update(int u, int L, int R, int st, int ed, int s) {
	if(L >= ed || R <= st) return 0;
	
	if(L >= st and R <= ed) {
		flag[u] += s;
		ma[u] += s;
		return 0;
	}
	
	push_down(u);
	update(ls, L, mid, st, ed, s);
	update(rs, mid, R, st, ed, s);
	push_up(u);
}

int calc(int u, int L, int R, int st, int ed) {
	if(L + 1 == R) return L;
	
	push_down(u);
	
	if(mid >= st and ma[rs] > 0) return calc(rs, mid, R, st, ed);
	return calc(ls, L, mid, st, ed);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int m;
	gn(m);
	for(int i=1; i<=m; i++) {
		gn(p[i], t[i]);
		if(t[i]) gn(val[i]);
	}
	
	for(int i=1; i<=m; i++) {
		if(t[i] == 1) {
			update(1, 1, m+1, 1, p[i]+1, 1);
			pos[p[i]] = val[i];
		}
		else update(1, 1, m+1, 1, p[i]+1, -1);
		if(ma[1] <= 0) {
			printf("%d\n", -1);
			continue;
		}
		int id = calc(1, 1, m+1, 1, m+1);
		printf("%d\n", pos[id]);
	}
	
}