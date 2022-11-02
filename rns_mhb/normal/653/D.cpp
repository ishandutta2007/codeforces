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

#define M 55
#define N 505

struct edge_____{ int t, r, _____f, ____c; };

vector <edge_____> ___________g[M];

int st, fs, n, m, p;
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

int x[N], y[N], c[N];

bool check(long double mid) {
    int d; st = 1, fs = n;
    f1(i, 1, n) ___________g[i].clear();
    f1(i, 1, m) {
		d = min(1ll * p, (ll)(c[i] / mid));
		func(x[i], y[i], d);
    }
    int f = query();
    if (f >= p) return 1;
    return 0;
}

int main() {
    scanf("%d %d %d", &n, &m, &p);
    f1(i, 1, m) {
		scanf("%d %d %d", &x[i], &y[i], &c[i]);
		if (x[i] > n) assert(0);
    }
    long double up = 1e-10;
    long double st = 0, en = 1000000;
    while (en - st > up) {
        long double mid = (st + en) / 2;
        if (check(mid)) st = mid;
        else en = mid;
    }
    printf("%.7lf\n", (double)en * p);
}