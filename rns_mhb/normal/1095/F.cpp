#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <ll, pii> plp;

#define N 200010

ll a[N];
set <pli> s1;
set <plp> s2;
int f[N];

int find_rt(int x) {
    return f[x] == x ? x : f[x] = find_rt(f[x]);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        f[i] = i;
        scanf("%I64d", &a[i]);
        s1.insert(pli(a[i], i));
    }
    while(m --) {
        int x, y;
        ll z;
        scanf("%d%d%I64d", &x, &y, &z);
        s2.insert(plp(z, pii(x, y)));
    }
    ll ans = 0;
    while(1) {
        if(s2.empty() && s1.size() < 2) break;
        pli p, q;
        plp r;
        if(s1.size() > 1) {
            set <pli> :: iterator it = s1.begin();
            p = *it; it ++;
            q = *it;
        }
        if(s2.size() > 0) {r = *s2.begin();}
        if(s1.size() > 1 && (s2.empty() || p.first + q.first < r.first)) {
            ans += p.first + q.first;
            f[q.second] = p.second;
            s1.erase(q);
        }
        else {
            s2.erase(s2.begin());
            int x = r.second.first, y = r.second.second;
            int xx = find_rt(x), yy = find_rt(y);
            if(xx == yy) continue;
            ans += r.first;
            if(a[yy] > a[xx]) f[yy] = xx, s1.erase(pli(a[yy], yy));
            else f[xx] = yy, s1.erase(pli(a[xx], xx));
        }
    }
    printf("%I64d\n", ans);
}