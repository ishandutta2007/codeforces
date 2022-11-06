#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], spf[sz];

void sieve()
{
    for(int i=2; i<sz; i++) {
        if(spf[i]) continue;
        for(int j=i; j<sz; j+=i) spf[j] = i;
    }
}

vector <int> v[sz];

int main()
{
    sieve();

    int n;
    cin >> n;

    if(n == 2) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        printf("%lld\n", x * y / __gcd(x, y));
        exit(0);
    }

    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        while(x > 1) {
            int y = spf[x], k = 0;
            while(x % y == 0) x /= y, k++;
            v[y].push_back(k);
        }
    }

    ll ans = 1;
    for(int i=2; i<sz; i++) {
        if(v[i].size() < n-1) continue;
        if(v[i].size() < n) v[i].push_back(0);
        sort(v[i].begin(), v[i].end());

        while(v[i][1]--) ans *= i;
    }

    cout << ans;
}