#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 2;
ll n, x, k;
vector<ll> A;

int main() {
    cin >> n >> x >> k;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ll lbnd = max(A[i], x*((A[i] + x - 1)/x + k - 1)), ubnd = x*((A[i] + x - 1)/x + k);
        //cout << lbnd << " " << ubnd << endl;
        auto it1 = lower_bound(A.begin(), A.end(), lbnd), it2 = lower_bound(A.begin(), A.end(), ubnd);
        //cout << *it1 << " " << *it2 << endl;
        ans += distance(it1, it2);
    }
    cout << ans << endl;
}