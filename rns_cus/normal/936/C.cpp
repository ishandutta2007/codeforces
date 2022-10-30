#include <bits/stdc++.h>
using namespace std;

#define N 2020

int n;
char ss[N], tt[N];
int pos, s[N], t[N], cnt[N], tmp[N];

vector <int> ans, vec[30];

void calc_vec() {
    for (int i = 0; i < 26; i ++) vec[i].clear();
    for (int i = n; i; i --) {
        if (s[i] != -1) vec[s[i]].push_back(i);
        else pos = i;
    }
}

void relax(int x) {
    if (!x) return;
    ans.push_back(x);
    for (int i = 1; i <= n; i ++) tmp[i] = s[i];
    for (int i = 1; i <= x; i ++) s[i] = tmp[n+1-i];
    for (int i = x + 1; i <= n; i ++) s[i] = tmp[i-x];
}

int main() {
    
    scanf("%d %s %s", &n, ss + 1, tt + 1);
    for (int i = 1; i <= n; i ++) {
        s[i] = ss[i] - 'a', t[i] = tt[i] - 'a';
        vec[s[i]].push_back(i);
        cnt[s[i]] ++, cnt[t[i]] --;
    }
    for (int i = 0; i < 26; i ++) if (cnt[i]) return puts("-1"), 0;
    pos = vec[t[1]][0];
    s[pos] = -1, calc_vec();
    for (int k = 1; k < n; k ++) {
        int x = vec[t[k+1]][0];
        s[x] = -1;
        if (x > pos) {
            relax(n - x), relax(n), relax(n + pos + k - x - 1);
            calc_vec();
        }
        else {
            relax(n - x), relax(1), relax(pos + k - 2);
            calc_vec();
        }
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i ++) printf("%d ", ans[i]);
    puts("");
}