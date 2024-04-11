#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e6 + 7;
const long long INF = 1e9 + 7;

int main() {
    long long n, m;
    cin >> n >> m;
    map <vector <long long>, long long> q;
    vector <vector <long long> > data(m);
    vector <long long> fact(MAXN, 1);
    long long now = 1;
    for (long long i = 1; i < MAXN; i++) {
        now *= i;
        now %= INF;
        fact[i] = now;
    }
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        for (long long j = 0; j < x; j++) {
            long long k;
            cin >> k;
            data[k - 1].push_back(i);
        }
    }
    for (long long i = 0; i < m; i++) {
        q[data[i]]++;
    }
    long long ans = 1;
    for (auto e : q) {
        ans *= fact[e.second];
        ans %= INF;
    }
    cout << ans;
}