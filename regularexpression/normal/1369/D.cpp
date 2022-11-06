#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
typedef long long ll;

const int mod = 1e9 + 7;

int add(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

int mult(int a, int b) {
    return (ll)a * b % mod;
}

const int go[6] = {1, mod - 1, 1, 0, 0, 0};

int ans[2000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i + 1 < 2000005; i++) {
        int delta = add(ans[i], go[(i - 1) % 6]);
        ans[i + 1] = add(ans[i], delta);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n--;
        cout << mult(ans[n], 4) << '\n';
    }
    return 0;
}