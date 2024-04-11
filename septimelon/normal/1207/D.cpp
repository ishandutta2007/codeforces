#include <bits/stdc++.h>

#define MAX 998244353

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll factmodMAX(int ma) {
    ll rez = 1;
    for (ll i = 2; i <= ma; i++) {
        rez *= i;
        if (rez > MAX)
            rez %= MAX;
    }
    return rez;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll ans, badl, badr, bad2;
    ans = factmodMAX(n);
    vector<int> ri;
    vector<pii> leri;
    int bufl, bufr;
    for (int i = 0; i < n; i++) {
        cin >> bufl >> bufr;
        ri.push_back(bufr);
        leri.push_back(pii(bufl, bufr));
    }
    sort(leri.begin(), leri.end());
    leri.push_back(pii(1000000, 1000000));
    int ind1 = 0;
    badl = 1;
    for (int i = 0; i <= n; i++) {
        if (leri[i].first == leri[ind1].first)
            continue;
        badl *= factmodMAX(i - ind1);
        badl %= MAX;
        ind1 = i;
    }
    bool bad2e = true;
    for (int i = 1; i <= n; i++) {
        if (leri[i].second >= leri[i-1].second)
            continue;
        bad2e = false;
        break;
    }
    if (bad2e) {
        bad2 = 1;
        ind1 = 0;
        for (int i = 0; i <= n; i++) {
            if (leri[i].first == leri[ind1].first && leri[i].second == leri[ind1].second)
                continue;
            bad2 *= factmodMAX(i - ind1);
            bad2 %= MAX;
            ind1 = i;
        }
    }
    else {
        bad2 = 0;
    }
    sort(ri.begin(), ri.end());
    ri.push_back(1000000);
    ind1 = 0;
    badr = 1;
    for (int i = 0; i <= n; i++) {
        if (ri[i] == ri[ind1])
            continue;
        badr *= factmodMAX(i - ind1);
        badr %= MAX;
        ind1 = i;
    }
    //cout << ans << " " << badl << " " << badr << " " << bad2 << endl;
    ans = ans - badl - badr + bad2 + (ll)(MAX * 2);
    ans %= MAX;
    cout << ans << endl;
    return 0;
}