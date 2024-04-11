#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double eps = 1e-10;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> fl = {0};
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fl.push_back(x);
    }
    fl.push_back(l);

    auto check = [&](double t) {
        double cur = t, dis = 0, v = 1, res = 0;
        for(int i = 1; i < fl.size(); i++) {
            double ti = (double)(fl[i] - fl[i - 1])/v;
            if(ti <= cur) {
                cur -= ti;
                dis += fl[i] - fl[i - 1];
                v++;
            }
            else {
                dis += cur * v;
                break;
            }
        }
        res += dis;
        cur = t;
        dis = 0;
        v = 1;
        for(int i = fl.size() - 2; i >= 0; i--) {
            double ti = (double)(fl[i + 1] - fl[i]) / v;
            if(ti <= cur) {
                cur -= ti;
                dis += fl[i + 1] - fl[i];
                v++;
            }
            else {
                dis += cur * v;
                break;
            }
        }
        return (res + dis) >= l + eps;
    };

    double lo = 0, hi = l;
    for(int it = 0; it < 200; it++) {
        double mi = (lo + hi)/2;
        if(check(mi))
            hi = mi;
        else
            lo = mi;
    }

    cout << fixed << setprecision(12) << lo << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}