#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;
typedef pair<int, int> P;
typedef long long ll;

int n, q;
int a[N];
int bds[2][N];
vector<int> nums;

ll solve(int l, int r) {
    vector<int> val;
    for(int i = l; i <= r; i++) val.push_back(nums[i]);
    ll res = 0;
    stack<P> S;
    for(int i = 0; i < val.size(); i++) {
        while(!S.empty() && S.top().first < val[i]) S.pop();
        int lb = S.empty() ? -1 : S.top().second;
        bds[0][i] = lb;
        S.push({val[i], i});
    }
    while(!S.empty()) S.pop();
    for(int i = val.size() - 1; i >= 0; i--) {
        while(!S.empty() && S.top().first <= val[i]) S.pop();
        int rb = S.empty() ? val.size(): S.top().second;
        bds[1][i] = rb;
        S.push({val[i], i});
    }
    for(int i = 0; i < val.size(); i++) {
        res += 1LL * (i - bds[0][i]) * (bds[1][i] - i) * val[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) nums.push_back(abs(a[i] - a[i-1]));
    n--;

    while(q--) {
        int l, r; cin >> l >> r; l--, r -= 2;
        cout << solve(l, r) << endl;
    }
}