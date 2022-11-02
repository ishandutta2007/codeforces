#include<bits/stdc++.h>
using namespace std;

#define N 300010

int n, p[N], a[N], b[N];
char s[9], c[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d%s", &p[i], s), c[i] = s[0];
    int x = 1, y = n, ans = 0;
    while(x <= n && c[x] == 'B') x ++;
    while(y && c[y] == 'B') y --;
    if(x < y) ans += p[y] - p[x];
    x = 1, y = n;
    while(x <= n && c[x] == 'R') x ++;
    while(y && c[y] == 'R') y --;
    if(x < y) ans += p[y] - p[x];
    vector <int> G;
    for(int i = 1; i <= n; i ++) if(c[i] == 'G') G.push_back(i);
    for(int i = 1; i < G.size(); i ++) {
        int l = G[i-1], r = G[i];
        int pr = p[l], pb = p[l], mr = 0, mb = 0;
        for(int j = l+1; j <= r; j ++) {
            if(c[j] != 'R') mb = max(p[j] - pb, mb), pb = p[j];
            if(c[j] != 'B') mr = max(p[j] - pr, mr), pr = p[j];
        }
        if(mr + mb > p[r] - p[l]) ans -= mr+mb-(p[r]-p[l]);
    }
    cout << ans << endl;
}