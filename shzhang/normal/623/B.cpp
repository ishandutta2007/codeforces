#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

ll prefix[10][1000005];
ll suffix[10][1000005];
ll arr[1000005]; int n; ll a, b;

vector<ll> prime_factors(ll val)
{
    ll origval = val;
    vector<ll> ans;
    ll cur = 2;
    while (val > 1) {
        if (val % cur == 0) {
            ans.push_back(cur);
            while (val % cur == 0) {
                val /= cur;
            }
        }
        cur++;
        if (cur * cur > origval) break;
    }
    if (val > 1) {
        ans.push_back(val);
    }
    return ans;
}

ll work(void)
{
    vector<ll> f1 = prime_factors(arr[1]);
    vector<ll> fn = prime_factors(arr[n]);
    for (int ind = 0; ind < f1.size(); ind++) {
        ll fac = f1[ind];
        bool over = false;
        for (int i = 1; i <= n; i++) {
            if (over) {
                prefix[ind][i] = -1000000000000000000LL; continue;
            }
            if (arr[i] % fac == 0) {
                prefix[ind][i] = prefix[ind][i-1] + a;
            } else if ((arr[i] + 1) % fac == 0 || (arr[i] - 1) % fac == 0) {
                prefix[ind][i] = prefix[ind][i-1] + a - b;
            } else {
                prefix[ind][i] = -1000000000000000000LL; over = true;
            }
        }
        for (int i = 2; i <= n; i++) prefix[ind][i] = max(prefix[ind][i-1], prefix[ind][i]);
    }

    for (int ind = 0; ind < fn.size(); ind++) {
        ll fac = fn[ind];
        bool over = false;
        for (int i = n; i >= 1; i--) {
            if (over) {
                suffix[ind][i] = -1000000000000000000LL; continue;
            }
            if (arr[i] % fac == 0) {
                suffix[ind][i] = suffix[ind][i+1] + a;
            } else if ((arr[i] + 1) % fac == 0 || (arr[i] - 1) % fac == 0) {
                suffix[ind][i] = suffix[ind][i+1] + a - b;
            } else {
                suffix[ind][i] = -1000000000000000000LL; over = true;
            }
        }
        for (int i = n-1; i >= 1; i--) suffix[ind][i] = max(suffix[ind][i], suffix[ind][i+1]);
    }

    vector<pair<int, int> > sames;

    for (int i = 0; i < f1.size(); i++) {
        for (int j = 0; j < fn.size(); j++) {
            if (f1[i] == fn[j]) {
                sames.push_back(make_pair(i, j));
            }
        }
    }

    ll maxearn = -1000000000000000000LL;

    for (int ind = 0; ind < sames.size(); ind++) {
        for (int i = 2; i < n; i++) {
            maxearn = max(maxearn, prefix[sames[ind].first][i-1] + suffix[sames[ind].second][i+1]);
        }
    }
    for (int i = 0; i < f1.size(); i++) {
        /*for (int j = 1; j <= n; j++) {
            printf("%lld ", prefix[i][j]);
        }
        printf("\n");*/
        maxearn = max(maxearn, prefix[i][n]);
    }

    //printf("---\n");

    for (int i = 0; i < fn.size(); i++) {
        /*for (int j = 1; j <= n; j++) {
            printf("%lld ", suffix[i][j]);
        }
        printf("\n");*/
        maxearn = max(maxearn, suffix[i][1]);
    }
    //printf("Result: %lld\n", a * n - maxearn);
    return a * n - maxearn;
}

int main()
{
    scanf("%d%lld%lld", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", arr + i);
    }

    int oldfirst = arr[1];
    int oldlast = arr[n];
    ll ans = 1000000000000000000LL;
    //int off1 = 0, offn = 0;
    for (int off1 = -1; off1 <= 1; off1++) {
        for (int offn = -1; offn <= 1; offn++) {
            arr[1] = oldfirst + off1;
            arr[n] = oldlast + offn;
            ans = min(ans, work() + b * ((off1 != 0 ? 1 : 0) + (offn != 0 ? 1 : 0)));
        }
    }

    printf("%lld", ans);

    return 0;
}