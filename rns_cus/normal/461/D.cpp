#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 201000
vector<int> v[N];
int fa[N], val[N];
int Find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = Find(fa[x]);
}
char s[100];
int main() {
    //freopen("1.in", "r", stdin);
    int n, K;
    scanf("%d%d", &n, &K);
    int ans = n;
    int cnt = 0;
    for(int i = 0; i <= n * 2 + 1; i ++) fa[i] = i, val[i] = i, v[i].push_back(i);
    for(int i = 0; i < K; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        scanf("%s", s);
        int va = 0;
        if(s[0] == 'o') va = 1;
        if(x < y) swap(x, y);
        if(x + y > n + 1) {
            int x1 = x;
            x = n + 1 - y;
            y = n + 1 - x1;
        }
        //printf("%d %d %d\n", x, y, va);
        int st, en;
        if((x + y - 1) % 2) {
            st = (x - y) / 2 + 1;
            en = (x + y) / 2;
        } else {
            st = n + (x - y + 1) / 2;
            en = n + (x + y - 1) / 2;
        }
        en ++;
        int f1 = Find(st);
        int f2 = Find(en);
        if(f1 != f2) {
            ans --;
            x = val[st];
            y = val[en];
            if(v[f1].size() > v[f2].size()) {
                swap(f1, f2);
                swap(x, y);
            }

            for(int j = 0; j < v[f1].size(); j ++) {
                int k = v[f1][j];
                v[f2].push_back(k);
                val[k] = y ^ va ^ val[k] ^ x;
            }
            fa[f1] = f2;
            v[f1].clear();
        } else {
            x = val[st];
            y = val[en];
            if((x ^ va) != y) {
                puts("0");
                return 0;
            }
        }
    }
    int va = 1;
    for(int i = 0; i < ans; i ++) va = va * 2 % mod;
    printf("%d\n", va);
}