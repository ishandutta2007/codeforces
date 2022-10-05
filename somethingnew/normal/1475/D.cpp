#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

void solve(){
    int n, m;
    vector<ll> vazn;
    vector<ll> nevazn;
    cin >> n >> m;
    vector<pair<ll, ll>> elems(n);
    for (auto &[i, v] : elems){
        cin >> i;
    }
    for (auto &[i, v] : elems){
        cin >> v;
        if (v == 1)
            nevazn.push_back(i);
        else
            vazn.push_back(i);
    }
    sort(all(vazn));
    sort(all(nevazn));
    vector<ll> prefvazn(vazn.size() + 1, 0);
    vector<ll> prefnevazn(nevazn.size() + 1, 0);
    int l = 0, r = n * 2 + 1;
    int nvs = nevazn.size(), vs = vazn.size();
    for (int i = 1; i <= nvs; ++i) {
        prefnevazn[i] = prefnevazn[i-1] + nevazn[i-1];
    }
    for (int i = 1; i <= vs; ++i) {
        prefvazn[i] = prefvazn[i-1] + vazn[i-1];
    }
    while (l + 1 < r){
        int mid = l + r >> 1;
        ll res = 0;
        for (int i = 0; i < min(nvs + 1, mid + 1); ++i) {
            res = max(res, prefnevazn[i] + prefvazn[min((mid - i) / 2, vs)]);
        }
        if (res >= m){
            r = mid;
        }else{
            l = mid;
        }
    }
    if (r != 2 * n + 1)
        cout << r << '\n';
    else
        cout << "-1\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}