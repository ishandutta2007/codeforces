#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define N 200010

ll w[N], h[N], c[N], a[N], b[N], ca[N], cb[N];

int main() {
    int n;
    scanf("%d", &n);
    map <pll, ll> mp;
    for(int i = 1; i <= n; i ++) {
        scanf("%I64d%I64d%I64d", &w[i], &h[i], &c[i]);
        mp[pll(w[i], h[i])] = c[i];
    }
    int x = 0, y = 0;
    for(int i = 1; i <= n; i ++) a[++ x] = w[i], b[++ y] = h[i];
    sort(a+1, a+x+1), sort(b+1, b+y+1);
    x = unique(a+1, a+x+1)-a-1, y = unique(b+1, b+y+1)-b-1;
    if(x * y != n) {
        puts("0");
        return 0;
    }
    vector <vector<ll> > v;
    v.resize(x+1);
    for(int i = 1; i <= x; i ++) {
        v[i].resize(y+1);
        for(int j = 1; j <= y; j ++) v[i][j] = mp[pll(a[i], b[j])];
    }
    ll g = v[1][1];
    vector <ll> d;
    for(int i = 1; 1ll*i*i <= g; i ++) if(g % i == 0) {
        d.push_back(i);
        if(1ll * i * i < g) d.push_back(g / i);
    }
    set <pll> s;
    for(int i = 0; i < d.size(); i ++) {
        ca[1] = d[i], cb[1] = g / d[i];
        for(int j = 1; j <= y; j ++) cb[j] = v[1][j] / ca[1];
        for(int j = 1; j <= x; j ++) ca[j] = v[j][1] / cb[1];
        bool flag = 0;
        for(int j = 1; j <= x; j ++) for(int k = 1; k <= y; k ++) {
            if(v[j][k] != ca[j] * cb[k]) {
                flag = 1;
                goto la;
            }
        }
        la:;
        if(flag) continue;
        ll A = 0, B = 0;
        for(int j = 1; j <= x; j ++) A += a[j] * ca[j];
        for(int j = 1; j <= y; j ++) B += b[j] * cb[j];
        s.insert(pll(A, B));
    }
    cout << s.size() << endl;
}