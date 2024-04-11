#include<bits/stdc++.h>
using namespace std;

#define fr first
#define se second
#define pb push_back
#define inf 1e9
#define INF 1e18
#define N 100010
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}

queue <int> q;
int d[N], s[N];

void solve() {
    int u, v;
    while(!q.empty()) {
        u = q.front(); q.pop();
        if(d[u] != 1) continue;
        v = s[u];
        s[v] ^= u;
        printf("%d %d\n", u, v);
        d[v] --;
        if(d[v] == 1) q.push(v);
    }
}

int main() {
    int n, i, e = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i ++) {
        scanf("%d%d", d + i, s + i);
        e += d[i];
        if(d[i] == 1) q.push(i);
    }
    printf("%d\n", e / 2);
    solve();
    return 0;
}