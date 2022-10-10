#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int winner_normal(ll e, ll s) {
    if(e % 2 == 0)
        return s % 2;
    ll tres = (e - 1)/2LL;
    if(s > tres)
        return (s % 2) ^ 1;
    if(s >= (tres + 2) / 2)
        return 0;
    return winner_normal((tres + 2)/2, s);
}

// 0 = first 1 = second
int winner_misere(ll e, ll s) {
    ll autowin = (e + 1LL)/2LL;
    if(s >= autowin)
        return 0;
    if(autowin % 2 == 0)
        return s % 2;
    ll uwu = (autowin - 1) / 2;
    if(s <= uwu)
        return winner_misere(uwu + 1, s);
    return (s % 2) ^ 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //int n;
    //cin >> n;
    //for(int i = 1; i < n; i++)
    //    cout << i << " " << winner_normal(n, i) << " " << winner_misere(n, i) << endl;

    // first bit - can start
    // second bit - can be second
    int guar = 1;
    int n;
    cin >> n;
    while(n--) {
        ll s, e;
        cin >> s >> e;
        e++;
        int tmp = 0;
        ll nm = winner_normal(e, s), ms = winner_misere(e, s);
        if(guar & 1) {
            if(nm == 0)
                tmp |= 2;
            if(ms == 0)
                tmp |= 1;
        }
        if(guar & 2) {
            if(nm == 1)
                tmp |= 2;
            if(ms == 1)
                tmp |= 1;
        }
        guar = tmp;
    }
    cout << (guar & 2)/2 << " " << (guar & 1) << '\n';
}