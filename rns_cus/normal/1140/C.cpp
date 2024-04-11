#include <bits/stdc++.h>
using namespace std;

#define N 300300

int k, n;

struct song{
    int t, b;
    bool operator < (const song &s) const {
        return b > s.b;
    }
    void in() {scanf("%d %d", &t, &b);}
} s[N];

multiset <int> ms;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++) s[i].in();
    sort(s, s + n);
    long long sum = 0, rlt = 0;
    for (int i = 0, sz = 0; i < n; i ++) {
        if (sz < k) {
            ms.insert(s[i].t); sz ++;
            sum += s[i].t;
            rlt = max(rlt, sum * s[i].b);
            continue;
        }
        int x = *ms.begin();
        if (s[i].t <= x) continue;
        sum += s[i].t - x;
        rlt = max(rlt, sum * s[i].b);
        ms.erase(ms.begin());
        ms.insert(s[i].t);
    }
    printf("%I64d\n", rlt);

    return 0;
}