#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {
    if (b == 0LL) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(5, 0);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        ++a[c];
    }
    
    int sum = 0;
    for (int i = 1; i < 5; ++i) {
        sum += i * a[i];
    }
    if (sum < 3 || sum == 5) {
        cout << "-1\n";
        return 0;
    }
    
    int mina = min(a[1], a[2]);
    a[1] -= mina;
    a[2] -= mina;
    a[3] += mina;
    int ca1 = a[1];
    if (a[1] > 0) {
        while (a[1] > 2) {
            mina += 2;
            a[1] -= 3;
            ++a[3];
        }
        ca1 = a[1];
        while (a[3] > 0 && a[1] > 0) {
            ++mina;
            --a[1];
            --a[3];
            ++a[4];
        }
        if (a[1] == 2) {
            mina += 2;
        } else if (a[1] == 1) {
            if (ca1 == a[1]) {
                mina += 2;
            } else if (ca1 == a[1] + 1) {
                ++mina;
            }
        }
    } else if (a[2] > 0) {
        while (a[2] > 1) {
            mina += 2;
            a[3] += 2;
            a[2] -= 3;
        }
        if (a[2] == 1) {
            if (a[4] > 0) {
                ++mina;
            } else {
                mina += 2;
            }
        }
    }
    
    cout << mina << "\n";
    
    return 0;
}