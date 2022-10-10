#include <bits/stdc++.h>
using namespace std;

vector<int> pset(int n) {
    vector<int> ans;
    for(int p = 2; p <= n; p++) {
        if(n % p)
            continue;
        ans.push_back(p);
        while(n % p == 0)
            n /= p;
    }
    return ans;
}

int divs(int n) {
    int ans = 0;
    for(int d = 1; d <= n; d++)
        if(n % d == 0)
            ans++;
    return ans;
}

int qry(int h, int w, int i1, int j1, int i2, int j2) {
    cout << "? " << h << " " << w << " " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
    int t;
    cin >> t;
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int row_per = m, col_per = n;

    auto v = pset(m);
    for(auto p : v) {
        while(row_per % p == 0) {
            int b_sz = row_per / p, nb = p / 2;
            if(p == 2) {
                if(!qry(n, nb * b_sz, 1, 1, 1, 1 + nb * b_sz))
                    break;
            }
            else {
                if(!qry(n, nb * b_sz, 1, 1, 1, 1 + nb * b_sz) || !qry(n, nb * b_sz, 1, 1, 1, 1 + nb * b_sz + b_sz))
                    break;
            }
            row_per /= p;
        }
    }

    v = pset(n);
    for(auto p : v) {
        while(col_per % p == 0) {
            int b_sz = col_per / p, nb = p / 2;
            if(p == 2) {
                if(!qry(nb * b_sz, m, 1, 1, 1 + nb * b_sz, 1))
                    break;
            }
            else {
                if(!qry(nb * b_sz, m, 1, 1, 1 + nb * b_sz, 1) || !qry(nb * b_sz, m, 1, 1, 1 + nb * b_sz + b_sz, 1))
                    break;
            }
            col_per /= p;
        }
    }

    cout << "! " << divs(m / row_per) * divs(n / col_per) << endl;
}