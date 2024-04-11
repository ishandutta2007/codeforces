#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

vector<int> poz;
const int N = 30000;

int l[N], p[N], prefy[N], dp[N], sufy[N];

#define INF 100000000000000000LL

int32_t main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> p[i];
    }
    poz.pb(x);
    for (int i = 1; i <= n; i++) {
        poz.pb(l[i]);
        poz.pb(p[i]);
    }
    sort(poz.begin(), poz.end());
    poz.erase(unique(poz.begin(), poz.end()), poz.end());

    for (int i = 0; i < poz.size(); i++) {
        if (poz[i] == x)
            dp[i] = 0;
        else
            dp[i] = INF;
    }

    for(int ii = 1; ii <= n; ii++) {

        prefy[0] = dp[0] - poz[0];
        sufy[poz.size() - 1] = dp[poz.size() - 1] + poz[poz.size() - 1];

        for (int i = 1; i < poz.size(); i++) {
            prefy[i] = min(prefy[i-1], dp[i] - poz[i]);
        }

        for (int i = ((int)poz.size()) - 2; i >= 0; i--) {
            sufy[i] = min(sufy[i+1], dp[i] + poz[i]);
        }

        for (int j = 0; j < poz.size(); j++) {
            dp[j] = min(sufy[j] - poz[j], prefy[j] + poz[j]);
        }

        for (int i = 0; i < poz.size(); i++) {
            if (poz[i] >= l[ii] && poz[i] <= p[ii])
                continue;
            dp[i] += min(abs(poz[i] - l[ii]), abs(poz[i] - p[ii]));
        }
    }
    int wynik = 1e18;
    for (int i = 0; i < poz.size(); i++) {
        wynik = min(wynik, dp[i]);
    }
    cout << wynik;
    return 0;
}