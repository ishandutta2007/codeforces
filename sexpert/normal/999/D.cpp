#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
vector<int> a[MAXN], v, uwu;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tot = 0;
    int n, m;
    cin >> n >> m;
    int k = n / m;
    v.resize(n);
    for(auto &x : v)
        cin >> x;
    for(int i = 0; i < n; i++)
        a[v[i]%m].push_back(i);
    for(int i = 0; i < m; i++) {
        while(a[i].size() > k) {
            int x = a[i].back();
            a[i].pop_back();
            uwu.push_back(x);
        }
        while(uwu.size() && a[i].size() < k) {
            int j = uwu.back(); uwu.pop_back();
            a[i].push_back(j);
            int d = (i - (v[j] % m) + m) % m;
            v[j] += d;
            tot += d;
        }
    }
    for(int i = 0; i < m; i++) {
        while(a[i].size() > k) {
            int x = a[i].back();
            a[i].pop_back();
            uwu.push_back(x);
        }
        while(uwu.size() && a[i].size() < k) {
            int j = uwu.back(); uwu.pop_back();
            a[i].push_back(j);
            int d = (i - (v[j] % m) + m) % m;
            v[j] += d;
            tot += d;
        }
    }
    cout << tot << '\n';
    for(auto x : v)
        cout << x << " ";
    cout << '\n';
}