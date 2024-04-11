#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
map<int, int> inv;
int prime[MAXN], t;

void sieve() {
    for(int p = 2; p < MAXN; p++) {
        if(!prime[p])
            inv[p] = ++t;
        for(int q = p; q < MAXN; q += p) {
            if(!prime[q])
                prime[q] = p;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++)
        cout << inv[prime[i]] << " ";
    cout << '\n';
}