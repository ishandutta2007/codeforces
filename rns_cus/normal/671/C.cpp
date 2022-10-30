#include <bits/stdc++.h>
using namespace std;
#define N 200000
#define M N + 100
vector<int> v[M];
vector<int> DD[M];
int a[M];
void prepare() {
    for(int i = 1; i <= N; i ++) {
        for(int j = 1; j * i <= N; j ++) {
            v[j * i].push_back(i);
        }
    }
}
typedef pair<int, int> pi;
set<pi> S;
set<pi> ::iterator it, it1;

pi er[M];
typedef long long ll;
ll ans;
#define NN -1

void doit(int x, int y, int i) {
    if(y < x) return ;
    pi A = pi(x, 0);
    it = S.lower_bound(A);
    int en = x - 1;
    if(it != S.begin()) {
        it --;
        pi b = *it;
        en = b.second;
        it ++;
    }
    if(en < x) en = x - 1;
    if(en >= y) return ;
    if(i == NN) {
        printf("A%d %d %d\n", x, y, en);
        for(it1 = S.begin(); it1 != S.end(); it1 ++) {
            pi b = *it1;
            printf("B%d %d\n", b.first, b.second);
        }
    }
    if(it == S.end()) {
        ans = ans + 1ll * i * (y - x + 2) * (y - x + 1) / 2;
        ans = ans - 1ll * i * (en - x + 2) * (en - x + 1) / 2;
        A = pi(x, y);
        S.insert(A);
        return ;
    }

    int cnt = 0;
    int st = x;
    while(1) {
        pi b = *it;
        if(b.first > y) break;
        if(en == x - 1) {
            ans = ans + 1ll * i * (b.first - st + 1) * (b.first - st) / 2;
            ans = ans + 1ll * i * (b.first - st) * (y - b.first + 1) ;
        }
        else {
            int xx = y;
            ans = ans + 1ll * i * (xx - st + 2) * (xx - st + 1) / 2;
            ans = ans - 1ll * i * (en - st + 2) * (en - st + 1) / 2;
            ans = ans - 1ll * i * (xx - b.first + 2) * (xx - b.first + 1) / 2;
            if(en >= b.first) ans = ans + 1ll * i * (en - b.first + 2) * (en - b.first + 1) / 2;
        }
        if(i == NN) printf("%d %d %d %d %I64d\n", st, en, b.first, b.second, ans);
        if(b.second <= y) er[cnt ++] = b;
        st = b.first;
        en = b.second;
        if(b.second >= y) break;
        it ++;
        if(it == S.end()) break;
    }
    if(i == NN) {
        printf("%I64d\n", ans);
    }
    if(en < y) {
        ans = ans + 1ll * i * (y - st + 2) * (y - st + 1) / 2;
        ans = ans - 1ll * i * (en - st + 2) * (en - st + 1) / 2;
    }
    //if(i == 5)printf("%I64d\n", ans);
    for(int i = 0; i < cnt; i ++) {
        S.erase(er[i]);
    }
    A = pi(x, y);
    S.insert(A);
}

int main() {
    //freopen("2.in", "r", stdin);
    int n;
    prepare();
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) {
        int x = a[i];
        for(int j = 0; j < v[x].size(); j ++) {
            int k = v[x][j];
            DD[k].push_back(i);
        }
    }
    ans = 0;
    for(int i = N; i; i --) {
        int sz = DD[i].size();
        if(sz < 2) continue;
        int x = DD[i][0];
        int y = DD[i][sz - 1];
        doit(x + 1, y - 1, i);
        doit(1, DD[i][sz - 2] - 1, i);
        doit(DD[i][1] + 1, n, i);
        //printf("%d %I64d\n", i, ans);
    }
    printf("%I64d\n", ans);
    return 0;
}