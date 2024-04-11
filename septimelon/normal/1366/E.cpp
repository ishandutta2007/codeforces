#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int q = 0; q < n; ++q) {
        if (a[q] < b[0]) {
            cout << "0" << endl;
            return 0;
        }
    }
    
    vector<long long> ll(m, 0LL);
    vector<long long> rl(m, 0LL);
    
    int cib = m - 1;
    int curr = -1;
    for (int cia = n - 1; cia >= 0; --cia) {
        if (cib == 0) {
            break;
        }
        if (a[cia] == b[cib] && curr == -1) {
            curr = cia;
        }
        if (a[cia] < b[cib]) {
            if (curr == -1) {
                cout << "0" << endl;
                return 0;
            }
            ++cia;
            ll[cib] = cia;
            rl[cib] = curr;
            curr = -1;
            --cib;
        }
    }
    bool cantry = false;
    ll.push_back(n);
    for (int i = 0; i < ll[1]; ++i) {
        if (a[i] == b[0]) {
            cantry = true;
            break;
        }
    }
    if (!cantry) {
        cout << "0" << endl;
        return 0;
    }
    
    long long ans = 1LL;
    for (int i = 0; i < m; ++i) {
        ans *= rl[i] - ll[i] + 1;
        ans %= 998244353LL;
    }
    
    cout << ans << endl;
    
    return 0;
}