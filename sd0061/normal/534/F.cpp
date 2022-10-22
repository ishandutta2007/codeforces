#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m;

vector<int> c[5];
int a[5] , b[20] , E;
void dfs(int k , int msk , int s) {
    if (k == n)
        c[s].push_back(msk);
    else {
        dfs(k + 1 , msk << 1 , s);
        dfs(k + 1 , msk << 1 | 1 , s + (~msk & 1));
    }
}
char res[40][40];
int power[10];
set<int> h[40][40];
bool DFS(int s , int mask , int f) {
    if (s == m) {
        return f == E;
    }
    for (int i = 0 ; i < n ; ++ i) {
        int x = f / power[i] % 11;
        if (x > a[i])
            return 0;
        if (x + (m - s + 1) / 2 < a[i])
            return 0;
    }
    if (h[s][mask].count(f))
        return 0;
    for (auto nxt : c[b[s]]) {
        int g = f;
        for (int i = 0 ; i < n ; ++ i) {
            if ((~mask >> i & 1) && (nxt >> i & 1))
                g += power[i];
        }
        if (DFS(s + 1 , nxt , g)) {
            for (int i = 0 ; i < n ; ++ i)
                res[i][s] = ".*"[nxt >> i & 1];
            return 1;
        }
    }
    h[s][mask].insert(f);
    return 0;
}

void work() {
    cin >> n >> m;
    dfs(0 , 0 , 0);
    for (int i = 0 ; i < n ; ++ i) cin >> a[i];
    for (int i = 0 ; i < m ; ++ i) cin >> b[i];
    power[0] = 1;
    for (int i = 1 ; i <= 5 ; ++ i) power[i] = power[i - 1] * 11;
    for (int i = 0 ; i < n ; ++ i)
        E += power[i] * a[i];
    DFS(0 , 0 , 0);
    for (int i = 0 ; i < n ; ++ i) puts(res[i]);
}

int main() {
    work();
    return 0;
}