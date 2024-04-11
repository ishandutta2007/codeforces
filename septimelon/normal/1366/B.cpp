#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    vector<int> lr;
    lr.push_back(2 * x);
    lr.push_back(2 * x + 1);
    int cop = 0;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l *= 2;
        r = r * 2 + 1;
        cop = 0;
        for (int j = 0; j < lr.size(); ++j) {
            if (lr[j] % 2 == 0) {
                ++cop;
            } else {
                --cop;
            }
            if (lr[j] >= r && lr[j] % 2 == 0 && cop == 1) {
                break;
            } else if (lr[j] >= l) {
                lr.push_back(l);
                lr.push_back(r);
                break;
            }
        }
        std::sort(lr.begin(), lr.end());
    }
    int totl = 0;
    int curl;
    cop = 0;
    for (int j = 0; j < lr.size(); ++j) {
        if (lr[j] % 2 == 0) {
            ++cop;
            if (cop == 1) {
                curl = lr[j];
            }
        } else {
            --cop;
            if (cop == 0) {
                totl += (lr[j] - curl + 1) / 2;
            }
        }
    }
    cout << totl << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}