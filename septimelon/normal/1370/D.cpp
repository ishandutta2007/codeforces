#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> vi = a;
    sort(vi.begin(), vi.end());
    
    int l = -1, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r + 1) / 2;
        int am = vi[mid];
        int ck[2] = {0, 0};
        for (int i = 0; i < n; ++i) {
            if (ck[0] % 2 == 0 && a[i] <= am) {
                ++ck[0];
            } else if (ck[0] % 2 == 1) {
                ++ck[0];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ck[1] % 2 == 1 && a[i] <= am) {
                ++ck[1];
            } else if (ck[1] % 2 == 0) {
                ++ck[1];
            }
        }
        if (ck[0] >= k || ck[1] >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << vi[r] << "\n";
    
    return 0;
}