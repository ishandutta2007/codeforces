#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 2;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, int >> a;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.push_back({x, i});
        sum += x;
    }
    vector<int> goods;
    sort(a.begin(), a.end());
    for(int i = 0; i < n - 1; i++) {
        if(sum - a[i].first == 2*a[n - 1].first)
            goods.push_back(a[i].second);
    }
    if(sum - a[n - 1].first == 2*a[n - 2].first)
        goods.push_back(a[n - 1].second);
    cout << goods.size() << endl;
    for(auto x : goods)
        cout << x + 1 << " ";
}