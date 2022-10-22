#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    ll ans = 0;
    for(int c = 0; c < 2; c++){
        map<int, vector<ll>> v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) v[a[i][j]].push_back(j);
        }
        for(auto itr = v.begin(); itr != v.end(); itr++){
            vector<ll> w = itr->second;
            sort(w.begin(), w.end());
            int k = w.size();
            vector<ll> l(k + 1), r(k + 1);
            for(int i = 1; i <= k; i++){
                l[i] = l[i - 1] + (m - w[i - 1]);
            }
            for(int i = k - 1; i >= 0; i--){
                r[i] = r[i + 1] + w[i];
            }
            for(int i = 0; i < k; i++){
                ans += l[i] - (m - w[i]) * i + r[i + 1] - w[i] * (k - 1 - i);
            }
        }
        vector<vector<ll>> b(m, vector<ll>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) b[i][j] = a[j][i];
        }
        swap(n, m);
        swap(a, b);
    }
    cout << ans / 2 << endl;
}