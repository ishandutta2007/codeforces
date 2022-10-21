#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;

int n, k;
ll ssum[N];

int main() {
    cin >> n >> k;
    ll res = 0;
    for(int i = 0; i < n; i++) cin >> ssum[i];
    for(int i = n - 1; i >= 0; i--) ssum[i] += ssum[i+1];
    res += ssum[0];
    sort(ssum + 1, ssum + n, greater<>());

    for(int i = 1; i < k; i++) res += ssum[i];
    cout << res << endl;
}