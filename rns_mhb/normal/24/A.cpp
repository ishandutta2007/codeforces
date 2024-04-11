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

#define N 105

int s[N], c[N][N], d[2];

int f(int u, int v) {
    int ret = c[u][v];
    if(v != 1) ret += f(v, s[v] - u);
    return ret;
}

int main() {
    int i, j = 0, n, u, v, cur, ans = inf, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i ++) {
        scanf("%d%d", &u, &v);
        scanf("%d", c[u] + v);
        s[v] += u;
        s[u] += v;
        if(u == 1 || v == 1) d[j ++] = u + v - 1;
    }
    printf("%d\n", min(f(1, d[0]), f(1, d[1])));
}