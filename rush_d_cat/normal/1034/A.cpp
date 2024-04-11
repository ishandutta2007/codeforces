#include <iostream>
using namespace std;
const int N = 300000 + 10;
int n,a[N];
const int MAXN = 15000002;
bool vis[MAXN];
int cnt[MAXN],f[MAXN];
void init() {
    for(int i=2;i<MAXN;i++) {
        if(vis[i]) continue;
        for(int j=i;j<MAXN;j+=i) {
            vis[j]=1; cnt[i] += f[j];
        }
    }
    //printf("%d\n", cnt[3]);
}
int gcd(int x, int y) {
    return y==0?x:gcd(y,x%y);
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]); 
    }
    int g = a[1];
    for(int i=2;i<=n;i++) {
        g = gcd(a[i], g);
    }
    for(int i=1;i<=n;i++) {
        a[i] /= g; f[a[i]] ++;
    }
    init();
    int mx = 0;
    for(int i=2;i<=15000000;i++) mx = max(mx, cnt[i]);
    if (mx == 0) return !printf("-1\n");
    printf("%d\n", n - mx);
}
// 2 3 5 6