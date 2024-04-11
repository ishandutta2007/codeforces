#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pc putchar
#define gc getchar
#define pb push_back
#define ppb pop_back
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f2(i, a, b) for (int i = a; i > b; i --)
#define f3(i, a, b) for (int i = a; i >= b; i --)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;
typedef vector <int> vi;

const int inf = 0x3f3f3f3f;
const ll linf = 2e18 + 100;
const double eps = 1e-7;

#define N 205
#define M 20005

int n, a[N];
bool vis[M];

vi v[2], w[N];

struct edge_____{ int t, r, f, c; };

vector <edge_____> ___________g[N];

int st, fs;
int d[N], q[N], ni[N];

void func(int s, int t, int c){
   edge_____ a = {t, ___________g[t].size(), 0, c};
   edge_____ b = {s, ___________g[s].size(), 0, 0};
   ___________g[s].push_back(a);
   ___________g[t].push_back(b);
}

int ds(int u, int f){
	if(u == fs) return f;
	int ret = 0;
	for(int &i = ni[u]; i < (int)___________g[u].size(); i ++){
		edge_____ &e = ___________g[u][i];
		if(e.c <= e.f) continue;
		int v = e.t;
		if(d[v] == d[u] + 1){
			int dddfff = ds(v, min(f, (int)(e.c - e.f)));
			if(dddfff > 0){
				e.f += dddfff;
				___________g[v][e.r].f -= dddfff;
				ret += dddfff;
				f -= dddfff;
				if(f == 0) return ret;
			}
		}
	}
	return ret;
}

int query(){
	int ans = 0;
	while(1){
		memset(d, -1, sizeof d);
		d[st] = 0;
		int qt = 0; q[qt ++] = st;
		for(int qh = 0; qh < qt; qh ++){
			int u = q[qh];
			for(int j = 0; j < (int)___________g[u].size(); j ++){
				edge_____ &e = ___________g[u][j];
				int v = e.t;
				if(d[v] < 0 && e.f < e.c){
					d[v] = d[u] + 1;
					q[qt ++] = v;
				}
			}
		}
		if (d[fs] < 0) break;
		memset(ni, 0, sizeof ni);
		ans += ds(st, inf);
	}
	return ans;
}

vi ww[N];
int ris[N], cs;
void dfs(int k) {
	ris[k] = 1; ww[cs].pb(k);
    for (auto x : w[k]) {
        if (ris[x]) continue;
        dfs(x);
    }
    return;
}

int main() {
    f0(i, 2, 200) if (!vis[i]) {
        for (int j = i * i; j < M; j += i) vis[j] = 1;
    }
    scanf("%d", &n);
    f1(i, 1, n) scanf("%d", &a[i]);
    if (n & 1) puts("Impossible");
    else {
		f1(i, 1, n) v[a[i]&1].pb(i);
		if (v[0].size() != v[1].size()) puts("Impossible");
        else {
            for (auto x : v[0]) for (auto y : v[1]) if (!vis[a[x] + a[y]]) func(x, y, 1);
            for (auto x : v[0]) func(n+1, x, 2);
            for (auto y : v[1]) func(y, n+2, 2);
            st = n+1, fs = n+2;
            int f = query();
            if (f != 2 * v[0].size()) puts("Impossible");
            else {
                for (auto x : v[0]) {
                    for (auto e : ___________g[x]) {
                        if (e.f == 1) {
                            w[x].pb(e.t);
                            w[e.t].pb(x);
                        }
                    }
                }
                f1(i, 1, n) if (!ris[i]) {
                    cs ++;
                    dfs(i);
                }
                printf("%d\n", cs);
                f1(i, 1, cs) {
					printf("%d ", ww[i].size());
					for (auto x : ww[i]) printf("%d ", x);
					puts("");
                }
            }
        }
    }

	return 0;
}