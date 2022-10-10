#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

struct gauss {
    vi mat, basis;
    int reduce(int n) {
        for(auto x : mat) {
            int msb = 1 << (31 - __builtin_clz(x));
            if(n & msb)
                n ^= x;
        }
        return n;
    }
    void add(int n) {
        int r = reduce(n);
        if(r) {
            basis.push_back(n);
            mat.push_back(r);
            sort(mat.rbegin(), mat.rend());
        }
    }
    bool has(int n) {
        n = reduce(n);
        return (n == 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vi S(n);
    for(auto &x : S)
        cin >> x;
    sort(S.begin(), S.end());
    for(int p = 20; p >= 0; p--) {
        int L = 1 << p;
        gauss G;
        for(auto s : S)
            if((s & (L - 1)) == s) G.add(s);
        bool good = true;
        for(int k = 0; k < p; k++) {
            if(!G.has(1 << k)) {
                good = false;
                break;
            }
        }
        if(!good)
            continue;
        vi basis = G.basis, code(L);
        for(int i = 1; i < L; i++)
            code[i] = i ^ (i >> 1);
        cout << p << endl;
        for(int i = 0; i < L; i++) {
            int res = 0;
            for(int b = 0; b < p; b++)
                if(code[i] & (1 << b)) res ^= basis[b];
            cout << res << " ";
        }
        cout << endl;
        return 0;
    }
}