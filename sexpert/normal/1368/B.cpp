#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string wow = "codeforces";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll k, tot = 1, idx = 0;
    cin >> k;
    vector<ll> cnt(10, 1);
    while(tot < k) {
        tot /= cnt[idx];
        cnt[idx]++;
        tot *= cnt[idx];
        idx = (idx + 1) % 10;
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < cnt[i]; j++)
            cout << wow[i];
    }
    cout << '\n';
}