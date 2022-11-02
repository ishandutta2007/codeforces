#include <bits/stdc++.h>
using namespace std;

vector<int> fact(int x) {
    vector<int> f;
    for (int i = 1; i*i <= x; i++) {
        if (x % i == 0) {
            f.push_back(i);
            if (x / i != i) {
                f.push_back(x / i);
            }
        }
    }
    return f;
}

bool ok(int W, int L, int f) {
    int A = W % f;
    if (A > 1) {
        return false;
    }
    int B = A ? L : L-1;
    B %= f;
    if (B > 1) {
        return false;
    }
    int C = B ? W : W-1;
    C %= f;
    if (C > 1) {
        return false;
    }
    int D = C ? L-1 : L-2;
    return D % f == 0;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int W, L;
        cin >> W >> L;
        vector<int> factors = fact(W);
        auto f2 = fact(W-1);
        auto f3 = fact(W-2);
        factors.insert(factors.end(), f2.begin(), f2.end()); 
        factors.insert(factors.end(), f3.begin(), f3.end()); 
        sort(factors.begin(), factors.end());
        factors.erase(unique(factors.begin(), factors.end()), factors.end());
        vector<int> ans;
        for (int f : factors) {
            if (ok(W, L, f) || ok(L, W, f)) {
                ans.push_back(f);
            }
        }
        cout << ans.size();
        for (int a : ans) {
            cout << " " << a;
        }
        cout << "\n";
    }
}