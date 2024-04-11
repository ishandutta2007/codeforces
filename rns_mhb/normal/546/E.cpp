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

#define N 105
#define M 230

int n, ____m;
int a[N], b[N];

struct edge_____{ int t, r, _____f, ____c; };

vector <edge_____> ___________g[M];

int st, fs;
int ___d[M], q[M], ni[M];

void func(int s, int t, int c){
   edge_____ __a = {t, ___________g[t].size(), 0, c};
   edge_____ __b = {s, ___________g[s].size(), 0, 0};
   ___________g[s].push_back(__a);
   ___________g[t].push_back(__b);
}

int ds(int u, int f){
	if(u == fs) return f;
	int ret = 0;
	for(int &i = ni[u]; i < (int)___________g[u].size(); i ++){
		edge_____ &e = ___________g[u][i];
		if(e.____c <= e._____f) continue;
		int v = e.t;
		if(___d[v] == ___d[u] + 1){
			int dddfff = ds(v, min(f, (int)(e.____c - e._____f)));
			if(dddfff > 0){
				e._____f += dddfff;
				___________g[v][e.r]._____f -= dddfff;
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
		memset(___d, -1, sizeof ___d);
		___d[st] = 0;
		int qt = 0; q[qt ++] = st;
		for(int qh = 0; qh < qt; qh ++){
			int u = q[qh];
			for(int j = 0; j < (int)___________g[u].size(); j ++){
				edge_____ &e = ___________g[u][j];
				int v = e.t;
				if(___d[v] < 0 && e._____f < e.____c){
					___d[v] = ___d[u] + 1;
					q[qt ++] = v;
				}
			}
		}
		if (___d[fs] < 0) break;
		memset(ni, 0, sizeof ni);
		ans += ds(st, inf);
	}
	return ans;
}


int x[N], y[N], s[N], dp[N][N];

int main() {
    int sa = 0, sb = 0;
    scanf("%d %d", &n, &____m);
    f1(i, 1, n) {
		scanf("%d", &a[i]);
        func(2*i-1, 2*i, a[i]);
		func(2*n+1, 2*i-1, a[i]);
		sa += a[i];
    }
    f1(i, 1, n) {
		scanf("%d", &b[i]);
        func(2*i-1, 2*n+2, b[i]);
        sb += b[i];
    }
    f1(i, 1, ____m) {
		scanf("%d %d", &x[i], &y[i]);
        func(2 * x[i], 2 * y[i] - 1, a[x[i]]);
        func(2 * y[i], 2 * x[i] - 1, a[y[i]]);
    }
    if (sa != sb) puts("NO");
    else {
        st = 2 * n + 1, fs = 2 * n + 2;
		if (query() != sa) puts("NO");
		else {
            puts("YES");
            f1(i, 1, n) {
                for (auto x : ___________g[i*2]) {
                    if (x._____f <= 0) continue;
                    dp[i][x.t+1>>1] = x._____f;
                    s[i] += x._____f;
                }
				dp[i][i] = a[i] - s[i];
            }
            f1(i, 1, n) {
				f1(j, 1, n) printf("%d ", dp[i][j]);
				puts("");
            }
		}
    }
	return 0;
}