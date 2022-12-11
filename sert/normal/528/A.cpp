#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e6 + 34;

ll h, w, n, p;
long long ans, mx, my;
char ch;
set <ll> x, y;
set <ll> :: iterator it, it2, it3;
set <pair<ll, ll> > bx, by;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%I64d%I64d%I64d ", &w, &h, &n);
    x.insert(0);
    x.insert(w);
    y.insert(0);
    y.insert(h);
    mx = w;
    my = h;
    bx.insert(make_pair(w, 0));
    by.insert(make_pair(h, 0));
    //cerr << mx << " " << my << " = \n";
    for (ll i = 0; i < n; i++) {
        scanf("%c %I64d ", &ch, &p);
        if (ch == 'H') {
            y.insert(p);
            it = y.find(p);
            it3 = it2 = it;
            it2--;
            it3++;
            by.erase(make_pair((*it3) - (*it2), *it2));
            by.insert(make_pair((*it3) - (*it), *it));
            by.insert(make_pair((*it) - (*it2), *it2));
        } else {
            x.insert(p);
            it = x.find(p);
            it3 = it2 = it;
            it2--;
            it3++;
            bx.erase(make_pair((*it3) - (*it2), *it2));
            bx.insert(make_pair((*it3) - (*it), *it));
            bx.insert(make_pair((*it) - (*it2), *it2));
        }
        mx = (bx.rbegin())->first;
        my = (by.rbegin())->first;
        //cerr << mx << " " << my << " = ";
        printf("%I64d\n", mx * my);
    }
    return 0;
}