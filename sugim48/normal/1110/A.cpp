#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

int main() {
    int b, N;
    cin >> b >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    int x = 0;
    rep(i, N) x = (x * b + a[i]) % 2;
    cout << (x % 2 == 0 ? "even" : "odd") << endl;
}