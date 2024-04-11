#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int main() {
    li n, k;
    cin >> n >> k;

    vector<li> d;
    for(int i = 1; i * 1ll * i <= n; i++) {
        if(n % i == 0) {
            d.push_back(i);
            if(i * 1ll * i != n)
                d.push_back(n / i);
        }
    }

    sort(d.begin(), d.end());

    cout << (k <= d.size() ? d[k - 1] : -1ll) << endl;
}