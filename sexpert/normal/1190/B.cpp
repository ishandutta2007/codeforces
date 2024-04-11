#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, dupe = -1, ct = 1;
    bool earlyfail = false;
    cin >> n;
    vector<int> v(n), red;
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    v.push_back(-1);
    for(int i = 1; i <= n; i++) {
        if(v[i] != v[i - 1]) {
            if(ct >= 3) {
                earlyfail = true;
                break;
            }
            if(ct == 2) {
                if(dupe != -1) {
                    earlyfail = true;
                    break;
                }
                dupe = v[i - 1];
            }
            ct = 1;
        }
        else
            ct++;
    }
    if(dupe != -1 && (dupe == 0 || find(v.begin(), v.end(), dupe - 1) != v.end()))
        earlyfail = true;
    if(earlyfail) {
        cout << "cslnb\n";
        return 0;
    }
    ll tot = 0;
    for(ll i = 0; i < n; i++)
        tot += v[i] - i;
    cout << (tot % 2 ? "sjfnb\n" : "cslnb\n");
}