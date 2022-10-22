#include <bits/stdc++.h>  
#define pb push_back  
#define lb lower_bound  
#define fi first  
#define se second  
#define mup(a,x) a=min(a,x)  
#define Mup(a,x) a=max(a,x)  
#define INF (1ll<<62)  
#define MOD 1000000007  
using namespace std;  
typedef long long LL;  
typedef unsigned long long ULL;  
typedef pair<int,int> pii;  
  
int N, Q, num;  
int A[303030], T[303030], D[303030];
int P[303030][20], G;
ULL C[303030];
vector<int> adj[303030];  
  
struct Node{  
    int lc, rc;
    ULL val;  
} M[10101010];  
  
void upd(int now, int pre, int s, int e, int t, ULL v){  
    M[now].val = M[pre].val ^ v;  
    if (s == e) return;  
    int m=s+e>>1;  
    if (t <= m){  
        M[now].lc = ++num, M[now].rc = M[pre].rc;  
        upd(M[now].lc, M[pre].lc, s, m, t, v);  
    }  
    else{  
        M[now].rc = ++num, M[now].lc = M[pre].lc;  
        upd(M[now].rc, M[pre].rc, m+1, e, t, v);  
    }  
}
  
void dfs(int u, int p){  
    T[u] = ++num, P[u][0] = p, D[u] = D[p] + 1;
    upd(T[u], T[p], 1, N, A[u], C[A[u]]);  
    for (int i=1; i<=18; i++) P[u][i] = P[P[u][i-1]][i-1];  
    for (int v : adj[u]){  
        if (v == p) continue;  
        dfs(v, u);
    }  
}

int bin(int id1, int id2, int s, int e, int l, int r){
	if (e < l || r < s) return -1;
	ULL x = M[id1].val ^ M[id2].val;
	if (s <= G && G <= e) x ^= C[G];
	if (!x) return -1;
	if (s == e) return s;
	int m=s+e>>1;
	int ret = bin(M[id1].lc, M[id2].lc, s, m, l, r);
	if (ret != -1) return ret;
	return bin(M[id1].rc, M[id2].rc, m+1, e, l, r);
}

int LCA(int u, int v){  
    if (D[u] > D[v]) swap(u, v);  
    for (int i=18; i>=0; i--) if (D[v]-D[u] >= (1<<i)) v=P[v][i];  
    if (u == v) return u;  
    for (int i=18; i>=0; i--) if (P[u][i] != P[v][i]) u=P[u][i], v=P[v][i];  
    return P[u][0];  
}  
  
int main(){
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int u, v, l, r;  
    scanf("%d %d", &N, &Q);  
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    for (int i=1; i<=N; i++){
    	C[i] = rng();
    	C[i] <<= 32;
    	C[i] |= rng();
    }
    for (int i=1; i<N; i++){  
        scanf("%d %d", &u, &v);  
        adj[u].pb(v), adj[v].pb(u);  
    }  
    dfs(1, 0);  
    while (Q--){  
        scanf("%d %d %d %d", &u, &v, &l, &r);
        G = A[LCA(u, v)];
        printf("%d\n", bin(T[u], T[v], 1, N, l, r));
    }  
    return 0;  
}