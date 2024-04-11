#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<int> v(m);
    for(auto &x : v)
        cin >> x;
    ll su = accumulate(v.begin(), v.end(), 0LL);
    if(su < n) {
        cout << "-1\n";
        return 0;
    }
    vector<int> ans(m);
    int bnd = n, rem = m - 1;
    int po = 1, lst = 0;
    for(int i = 0; i < m; i++) {
        int l = v[i];
        su -= l;
        po = lst + 1;
        while(po + l - 1 + su < n)
            po++;
        if(po + l - 1 > n) {
            cout << "-1\n";
            return 0;
        }
        lst = po;
        ans[i] = po;
    }
    for(auto x : ans)
        cout << x << " ";
    cout << '\n';
}