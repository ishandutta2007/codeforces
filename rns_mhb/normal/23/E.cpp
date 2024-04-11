#include<bits/stdc++.h>
using namespace std;

#define fr first
#define se second
#define pb push_back

#define inf 1e9
#define INF 1e18

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}

const ll base = 100000000;

struct bigint {
    ll d[60], len;
    void O() {memset(d, 0, sizeof d); len = 0;}
    void I() {d[1] = 1; len = 1;}
    bigint operator * (const int &a) const {
        bigint ret;
        ret.O();
        for(int i = 1; i <= len; i ++) ret.d[i] = d[i] * a;
        ret.len = len;
        for(int i = 1; i <= len; i ++) {
            ret.d[i + 1] += ret.d[i] / base;
            ret.d[i] %= base;
        }
        while(ret.d[ret.len + 1] > 0) {
            ret.d[ret.len + 2] += ret.d[ret.len + 1] / base;
            ret.d[ret.len + 1] %= base;
            ret.len ++;
        }
        return ret;
    }
    bigint operator * (bigint &a) const {
		bigint ret;
		ret.O();
		int i, j;
		for(i = 1; i <= len; i ++) for(j = 1;j <= a.len; j ++) ret.d[i + j - 1] += d[i] * a.d[j];
		ret.len = len + a.len - 1;
		for(i = 1; i <= ret.len; i ++) {
			ret.d[i + 1] += ret.d[i] / base;
			ret.d[i] %= base;
		}
		while(ret.d[ret.len + 1] > 0) {
			ret.d[ret.len + 2] += ret.d[ret.len + 1]/base;
			ret.d[ret.len + 1] %= base;
			ret.len ++;
		}
		return ret;
	}
	bool operator < (const bigint &a) const {
        if(len > a.len) return 0;
		if(a.len > len) return 1;
		for(int i = len; i > 0; i --) {
			if(d[i] > a.d[i]) return 0;
			if(a.d[i] > d[i]) return 1;
		}
		return 0;
	}
	void out() {
		printf("%I64d", d[len]);
		for(int i = len - 1;i > 0; i --) printf("%08I64d", d[i]);
		puts("");
	}
};

#define N 707

bigint f[N][N];
vi adj[N];
int sub[N], n;

void dfs(int u, int p) {
    int i, j, k, v;
    sub[u] = 1;
    for(i = 1; i <= n; i ++) f[u][i].I();
    for(i = 0; i < adj[u].size(); i ++) {
        v = adj[u][i];
        if(v == p) continue;
        dfs(v, u);
        sub[u] += sub[v];
        for(j = sub[u] - sub[v]; j >= 0; j --) for(k = sub[v]; k >= 0; k --) chkmax(f[u][j + k], f[u][j] * f[v][k]);
    }
    for(i = 1; i <= sub[u]; i ++) chkmax(f[u][0], f[u][i] * i);
}

int main() {
    int i, u, v;
    scanf("%d", &n);
    for(i = 1; i < n; i ++) {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    f[1][0].out();
}