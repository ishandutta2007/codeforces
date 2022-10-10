#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll v[MAXN];
vector<ll> diff;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    ll ans = n;
    int num = n;
    for(int i = 1; i < n; i++)
        diff.push_back(v[i] - v[i - 1]);
    sort(diff.begin(), diff.end());
    int ptr = 0;
    while(num > k) {
        num--;
        ans += diff[ptr] - 1;
        ptr++;
    }
    cout << ans << endl;
}