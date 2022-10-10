#include <bits/stdc++.h>
using namespace std;

struct prob {
    int k, t, idx;
    bool operator< (const prob &o) const {
        return t < o.t;
    }
};

int main() {
    int n, T;
    cin >> n >> T;
    vector<prob> test;
    for(int i = 1; i <= n; i++) {
        int k, t;
        cin >> k >> t;
        test.push_back(prob{k, t, i});
    }
    sort(test.begin(), test.end());
    int lo = 0, hi = n;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2, s = 0, taken = 0;
        for(int i = 0; i < n; i++) {
            if(test[i].k >= mi && s + test[i].t <= T) {
                taken++;
                s += test[i].t;
            }
        }
        if(taken >= mi)
            lo = mi;
        else
            hi = mi - 1;
    }
    int taken = 0;
    cout << lo << endl << lo << endl;
    for(int i = 0; i < n; i++) {
        if(taken == lo)
            break;
        if(test[i].k >= lo)
            taken++, cout << test[i].idx << " ";
    }
    cout << endl;
}