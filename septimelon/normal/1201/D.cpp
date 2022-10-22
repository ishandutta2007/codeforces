#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> b;
int q;

ll minpath (int i1, int i2) {
    int mi = min(i1, i2);
    int ma = max(i1, i2);
    int l = 0;
    int r = q+1;
    while (r - l > 1) {
        if (b[(l + r) / 2] < mi) {
            l = (l + r) / 2;
        }
        else {
            r = (l + r) / 2;
        }
    }
    if (b[l+1] <= ma)
        return ma - mi;
    return min (mi + ma - 2 * b[l], 2 * b[l+1] - mi - ma);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k >> q;
    vector<vector<ll>> soc(n);
    ll in1, in2;
    for (int i = 0; i < k; i++) {
        cin >> in1 >> in2;
        soc[in1-1].push_back(in2-1);
    }
    for (int i = 0; i < n; i++) {
        if (soc[i].size() < 2)
            continue;
        sort(soc[i].begin(), soc[i].end());
    }
    int topind = n-1;
    while (soc[topind].size() == 0)
        topind--;
    b.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> b[i];
        b[i]--;
    }
    b.push_back(9999999);
    b.push_back(-999999);
    sort(b.begin(), b.end());
    ll minl = 0;
    ll minr = 0;
    ll lastl, lastr;
    if (soc[0].size() == 0) {
        lastl = 0;
        lastr = 0;
    }
    else {
        lastl = soc[0][0];
        lastr = soc[0][soc[0].size()-1];
        minl = soc[0][soc[0].size()-1] * 2 - soc[0][0];
        minr = soc[0][soc[0].size()-1];
    }
    ll minl2;
    ll minr2;
    for (int qq = 1; qq <= topind; qq++) {
        //cout << minl << "-" << minr << endl;
        if (soc[qq].size() == 0)
            continue;
        minr2 = min(minl + minpath(lastl, soc[qq][0]) + soc[qq][soc[qq].size()-1] - soc[qq][0],
                    minr + minpath(lastr, soc[qq][0]) + soc[qq][soc[qq].size()-1] - soc[qq][0]);
        minl2 = min(minl + minpath(lastl, soc[qq][soc[qq].size()-1]) + soc[qq][soc[qq].size()-1] - soc[qq][0],
                    minr + minpath(lastr, soc[qq][soc[qq].size()-1]) + soc[qq][soc[qq].size()-1] - soc[qq][0]);
        minl = minl2;
        minr = minr2;
        lastl = soc[qq][0];
        lastr = soc[qq][soc[qq].size()-1];
    }
        //cout << minl << "-" << minr << endl;
    cout << min(minl, minr) + topind << endl;
    return 0;
}