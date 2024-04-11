#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

#define ll long long
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int c, s;
        cin >> c >> s;
        c = min(c, s);
        int x = s / c;
        int k = c * x + c - s;
        cout << k * x * x + (c - k) * (x + 1) * (x + 1) << '\n';
    }
    return 0;
}