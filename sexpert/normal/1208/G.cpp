#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
int prime[MAXN];

void sieve() {
    for(int p = 2; p < MAXN; p++) {
        if(prime[p])
            continue;
        for(int q = p; q < MAXN; q += p)
            prime[q] = p;
    } 
}

int phi(int n) {
    int res = n;
    while(n > 1) {
        int p = prime[n];
        res /= p;
        res *= (p - 1);
        while(n % p == 0)
            n /= p;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();

    int n, k;
    cin >> n >> k;
    if(k == 1) {
        cout << "3\n";
        return 0;
    }
    k += 2;
    priority_queue<int, vector<int>, greater<int>> pq;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        pq.push(phi(i));
    for(int i = 0; i < k; i++) {
        int v = pq.top(); pq.pop();
        ans += v;
    }
    cout << ans << '\n';
}