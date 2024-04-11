#include <bits/stdc++.h>

#define MAX 500

using namespace std;

typedef long long ll;

/*bool ost(int del, int x, int y) {
    if (del >= 0) {
        if (del % x == y)
            return true;
        else
            return false;
    }
    del = 0 - del;
    del %= x;
    del = 0 - del;
    del += x;
    if (del == x)
        del = 0;
    if (del == y)
        return true;
    else
        return false;
}*/

int main()
{
    vector<int> a(500001, 0);
    int cou[MAX][MAX];
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cou[i][j] = 0;
    int q, t, x, y;
    cin >> q;
    int ans;
    for (int qq = 0; qq < q; qq++) {
        cin >> t >> x >> y;
        if (t == 1) {
            a[x] += y;
            for (int i = 1; i <= MAX; i++)
                cou[i-1][x%i] += y;
        }
        else {
            ans = 0;
            if (x > MAX) {
                for (int ind = (y + x - 1) % x + 1; ind < 500001; ind += x) {
                    ans += a[ind];
                }
            }
            else {
                ans += cou[x-1][y];
            }
            cout << ans << endl;
        }
    }
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    /*int curma = 0;
    int curmi = 0;
    int q;
    cin >> q;
    vector<int> a(500000, 0);
    vector<bool> out(500000, false);
    vector<int> mor(500001, 0);
    vector<int> men(500001, 0);
    vector<int> outadr;
    mor[0] = 500000;
    int t, x, y;
    ll ind, ans;
    for (int qq = 0; qq < q; qq++) {
        cin >> t >> x >> y;
        if (t == 1) {
            x--;
            if (!out[x]) {
                if (a[x] >= 0) {
                    mor[a[x]]--;
                }
                else {
                    men[0 - a[x]]--;
                }
                a[x] += y;
                if (abs(a[x]) < 500001) {
                    if (a[x] >= 0) {
                        mor[a[x]]++;
                    }
                    else {
                        men[0 - a[x]]++;
                    }
                }
                else {
                    out[x] = true;
                    outadr.push_back(x);
                }
                if (a[x] >= 0) {
                    curma = max(curma, a[x]);
                    curma = min(curma, 500000);
                }
                else {
                    curmi = min(curmi, a[x]);
                    curmi = max(curmi, -500000);
                }
                cout << curmi << " - " << curma << endl;
            }
            else {
                a[x] += y;
            }
        }
        else {
            ind = y;
            ans = 0;
            while (ind <= curma) {
                ans += (ll)(mor[ind]) * ind;
                ind += x;
            }
            ind = 0 - (y - x);
            while (ind <= 0 - curmi) {
                ans += (ll)(men[ind]) * ind;
                ind += x;
            }
            for (int i = 0; i < outadr.size(); i++) {
                if (ost(a[outadr[i]], x, y))
                    ans += a[outadr[i]];
            }
            cout << ans << endl;
        }
    }*/
    return 0;
}