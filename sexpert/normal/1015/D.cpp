#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k, s;
    cin >> n >> k >> s;
    if(s > k * (n - 1) || s < k) {
        cout << "NO\n";
        return 0;
    }
    ll fl = s / k;
    ll lng = s - k * fl;
    vector<ll> ps;
    ps.push_back(1);
    for(int i = 0; i < k; i++) {
        ll df;
        if(i < lng)
            df = fl + 1;
        else
            df = fl;
        if(i % 2)
            ps.push_back(ps.back() - df);
        else
            ps.push_back(ps.back() + df);
    }
    cout << "YES\n";
    for(int i = 1; i < ps.size(); i++)
        cout << ps[i] << " ";
    cout << '\n';
}