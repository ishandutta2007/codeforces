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
    
    ll n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    
    ll nod = gcd(a.size(), b.size());
    vector<vector<int>> coua(nod, vector<int>('z' - 'a' + 1, 0));
    for (int i = 0; i < b.size(); ++i) {
        ++coua[i % nod][b[i] - 'a'];
    }
    
    ll ans = 0LL;
    for (int i = 0; i < a.size(); ++i) {
        ans += (n * nod / b.size()) * coua[i % nod][a[i] - 'a'];
        /*cout << n * nod / b.size() << " " << coua[i % nod][a[i] - 'a'] << endl;*/
    }
    ans = a.size() * n - ans;
    cout << ans << "\n";
    
    return 0;
}