#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> primes;
array<int, 700> pf[5005];
int prime[5005], cnt[5005];

void precalc() {
    for(int p = 2; p < 5005; p++) {
        if(prime[p])
            continue;
        primes.push_back(p);
        for(int q = p; q < 5005; q += p)
            prime[q] = p;
    }
    for(int k = 0; k <= 5000; k++) {
        array<int, 700> cur;
        for(int i = 0; i < primes.size(); i++) {
            cur[i] = 0;
            int p = primes[i];
            int mul = p;
            while(mul <= k) {
                cur[i] += k / mul;
                mul *= p;
            }
        }
        pf[k] = cur;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    precalc();
    int P = primes.size();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    ll ans = 0;
    int curc = n;
    for(int k = 0; k <= 5000; k++) {
        for(int i = 0; i < P; i++)
            ans += (ll)pf[k][i] * cnt[k];
    }
    int curP = P - 1, cure = 0;
    while(curc > n - curc && curP >= 0) {
        int nxtc = 10000;
        for(int k = 0; k <= 5000; k++) {
            if(cnt[k] == 0)
                continue;
            nxtc = min(nxtc, pf[k][curP]);
        }
        ans -= (ll)(nxtc - cure) * curc;
        ans += (ll)(nxtc - cure) * (n - curc);
        cure = nxtc;
        int tc = 0;
        for(int k = 0; k <= 5000; k++) {
            if(cnt[k] == 0 || pf[k][curP] == cure)
                continue;
            tc += cnt[k];
        }
        if(tc > n - tc) {
            curc = tc;
            for(int k = 0; k <= 5000; k++) {
                if(pf[k][curP] == cure)
                    cnt[k] = 0;
            }
        }
        else {
            curc = 0;
            for(int k = 0; k <= 5000; k++) {
                if(cnt[k] == 0)
                    continue;
                if(pf[k][curP] > cure)
                    cnt[k] = 0;
                else
                    curc += cnt[k];
            }
            curP--;
            cure = 0;
        }
    }
    cout << ans << '\n';
}