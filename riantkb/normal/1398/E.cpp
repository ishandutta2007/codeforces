#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    set<P> upper, lower;
    long long uppersum = 0, sum = 0;
    int c = 0, uc = 0;
    for (int i = 0; i < n; ++i) {
        int t, d;
        cin >> t >> d;
        P p(abs(d), t);
        if (d > 0) {
            c += t;
            sum += d;
            if (upper.size() > 0 && p > *upper.begin()) {
                upper.insert(p);
                uc += t;
                uppersum += d;
            }
            else {
                lower.insert(p);
            }
        }
        else {
            d = -d;
            c -= t;
            sum -= d;
            if (upper.count(p)) {
                upper.erase(p);
                uc -= t;
                uppersum -= d;
            }
            else {
                lower.erase(p);
            }
        }
        while ((int)upper.size() > c) {
            P p = *upper.begin();
            uppersum -= p.first;
            uc -= p.second;
            lower.insert(p);
            upper.erase(p);
        }
        while ((int)upper.size() < c) {
            P p = *lower.rbegin();
            uppersum += p.first;
            uc += p.second;
            upper.insert(p);
            lower.erase(p);
        }
        if (c == 0 || uc < c) {
            cout << sum + uppersum << '\n';
        }
        else if (lower.size()) {
            cout << sum + uppersum - (*upper.begin()).first + (*lower.rbegin()).first << '\n';
        }
        else {
            cout << sum + uppersum - (*upper.begin()).first << '\n';
        }
    }
    return 0;
}