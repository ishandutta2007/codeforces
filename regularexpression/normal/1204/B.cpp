#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    int mns = 0;
    for (int i = 0; i < l; ++i) {
        mns += (1LL << i);
    }
    mns += n - l;
    int mxxs = 0;
    for (int i = l; i <= r; ++i) {
        int mxs = 0;
        for (int j = 0; j < i; ++j) {
            mxs += (1LL << j);
        }
        mxs += (1LL << (i - 1)) * (n - i);
        mxxs = max(mxxs, mxs);
    }
    cout << mns << " " << mxxs << endl;
    return 0;
}