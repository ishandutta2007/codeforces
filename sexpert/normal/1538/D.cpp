#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 4e4 + 4;
vector<int> pr;
int prime[MAXN];

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    if(k == 1) {
        if(a == b)
            cout << "No\n";
        else {
            if(a % b == 0 || b % a == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        return;
    }

    int cnt = 0;
    for(auto &p : pr) {
        while(a % p == 0) {
            a /= p;
            cnt++;
        }
        while(b % p == 0) {
            b /= p;
            cnt++;
        }
    }
    if(a > 1)
        cnt++;
    if(b > 1)
        cnt++;
    cout << (cnt >= k ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int p = 2; p < MAXN; p++) {
        if(!prime[p]) {
            pr.push_back(p);
            for(int q = p; q < MAXN; q += p)
                prime[q] = 1;
        }
    }

    int t;
    cin >> t;
    while(t--)
        solve();
}