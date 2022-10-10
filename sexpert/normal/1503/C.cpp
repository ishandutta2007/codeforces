#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tp = array<int, 3>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll tot = 0;
    vector<tp> cities;

    for(int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        cities.push_back({a, c, i});
        tot += c;
    }
    sort(cities.begin(), cities.end());
    int idx = 0;
    ll bound = cities[0][0], pv_a = cities[0][0], pv_c = cities[0][1];

    while(idx < n) {
        if(cities[idx][0] > bound)
            tot += (cities[idx][0] - bound);
        pv_a = cities[idx][0];
        pv_c = cities[idx][1];
        bound = max(bound, pv_a + pv_c);
        idx++;
    }

    cout << tot << '\n';
}