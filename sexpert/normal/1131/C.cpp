#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n), ansl, ansr;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.rbegin(), v.rend());
    int mn = v[n - 1], ml = v[0], mr = v[0], dl = v[0] - mn, dr = v[0] - mn;
    for(int i = 1; i < n - 1; i++) {
        if(ml >= mr) {
            dl = max(ml - v[i], v[i] - mn);
            ml = v[i];
            ansl.push_back(v[i]);
        }
        else {
            dr = max(mr - v[i], v[i] - mn);
            mr = v[i];
            ansr.push_back(v[i]);
        }
    }
    cout << v[0] << " ";
    for(auto x : ansl)
        cout << x << " ";
    cout << mn << " ";
    for(int i = ansr.size() - 1; i >= 0; i--)
        cout << ansr[i] << " ";
    cout << endl;
}