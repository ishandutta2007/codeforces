#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 202;
typedef long long LL;
LL gcd(LL x, LL y) {
    return y == 0 ? x : gcd(y, x % y);
}
LL lcm(LL x, LL y) {
    return x * (y / gcd(x, y));
}

int n, par[N];
bool onring[N], vis[N];

LL ans = 1;
void init(int x) {
    memset(vis, 0, sizeof(vis));
    int now = x, len = 0;
    while (vis[now] == 0) {
        vis[now] = 1;
        now = par[now];
        ++ len;
    }
    if (now == x) {
        onring[x] = true;
        // printf("len = %d\n", len);
        ans = lcm(ans, len);
    }
}
int getlen(int x) {
    int len = 0;
    while(onring[x] == 0) {
        len ++;
        x = par[x];
    }
    return len;
}
void brt() {
    for(int i=1;;i++) {
        //printf("i=%d\n", i);
        bool ok=1;
        for(int x=1;x<=n;x++) {
            int t=x;
            for(int k=1;k<=i;k++) t=par[t];
            int c1=t;
            for(int k=1;k<=i;k++) t=par[t];
            int c2=t;
            if (c1!=c2) ok=0;    
        }
        if(ok){
            return;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x; scanf("%d", &x);
        // x = rand() % n + 1;
        par[i] = x;
    }
   
    for (int i = 1; i <= n; i ++) init(i);
    LL res = ans;
    for (int i = 1; i <= n; i ++) if (!onring[i]) {
        int len = getlen(i);
        if (len > ans) {
            res = max(( (len + ans - 1) / ans) * ans, res);
        }
    }
    cout << res << endl;
    // brt();
}