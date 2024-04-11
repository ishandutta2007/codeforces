#include<bits/stdc++.h>
using namespace std;

#define N 100010

int t, n, a[N], b[N];
char s[N];

char c[10] = "ANOT"; int order[300];
vector<int> pos[4];

struct fenwick {
    int vol;
    vector<int> member, f;
    fenwick(int vol) : vol(vol) {
        member.resize(vol + 1);
        f.resize(vol + 1);
    }
    void clear() {
        for(int i = 0; i <= n; i ++) member[i] = f[i] = 0;
    }
    void update(int r, int d) {
        for(int i = r; i <= vol; i += i & -i) f[i] += d;
    }
    void build() {
        for(int i = 1; i <= vol; i ++) update(i, member[i]);
    }
    int query(int r) {
        int sum = 0;
        while(r) {
            sum += f[r];
            r -= r & -r;
        }
        return sum;
    }
    int sum(int l, int r) {
        return query(r) - query(l - 1);
    }
} counter(N);

long long calc(int *b) {
    counter.clear();
    long long ans = 0;
    for(int i = n - 1; ~i; i --) {
        ans += counter.query(b[i] + 1);
        counter.update(b[i] + 1, 1);
    }
    return ans;
}

void solve() {
    n = strlen(s);
    for(int i = 0; i < 4; i ++) pos[i].clear();
    for(int i = 0; i < n; i ++) a[i] = order[s[i]];
    for(int i = 0; i < n; i ++) pos[a[i]].push_back(i);
    int p[4] = {0, 1, 2, 3};
    int q[4];
    long long ans = -1;
    do {
        for(int i = 0, j = 0; i < 4; i ++) for(int k = 0; k < pos[p[i]].size(); k ++) b[j ++] = pos[p[i]][k];
        long long d = calc(b);
        if(d > ans) {
            ans = d;
            for(int i = 0; i < 4; i ++) q[i] = p[i];
        }
    } while(next_permutation(p, p + 4));
    for(int i = 0, j = 0; i < 4; i ++) for(int k = pos[q[i]].size(); k --; ) printf("%c", c[q[i]]);
    puts("");
}

int main() {
    for(int i = 0; i < 4; i ++) order[c[i]] = i;
    for(scanf("%d", &t); t --; ) {
        scanf("%s", s);
        solve();
    }
}