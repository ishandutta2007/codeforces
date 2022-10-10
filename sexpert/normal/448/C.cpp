#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int solve(int l, int r) {
    int res = r - l + 1, cu = 0;
    int h = *min_element(v.begin() + l, v.begin() + r + 1);
    for(int i = l; i <= r; i++)
        v[i] -= h;
    int p = -1;
    for(int i = l; i <= r; i++) {
        if(v[i] == 0) {
            if(p != -1)
                cu += solve(p, i - 1);
            p = -1;
        }
        else {
            if(p == -1)
                p = i;
        }
    }
    if(p != -1)
        cu += solve(p, r);
    return min(res, h + cu);
}

int main() {
    int n, cur = 0, ans;
    cin >> n;
    v.resize(n);
    for(auto &x : v)
        cin >> x;
    cout << solve(0, n - 1) << '\n';
}