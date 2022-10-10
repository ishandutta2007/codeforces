#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll w, m;
    cin >> w >> m;
    if(w == 2) {
        cout << "YES\n";
        return 0;
    }
    vector<int> v;
    while(m) {
        v.push_back(m % w);
        m /= w;
    }
    int n = v.size();
    //for(auto x : v)
    //    cout << x << " ";
    //cout << '\n';
    for(int i = 0; i < n; i++) {
        if(v[i] == w) {
            v[i] = 0;
            if(i < n - 1)
                v[i + 1]++;
        }
        if(v[i] > 1 && v[i] < w - 1) {
            cout << "NO\n";
            return 0;
        }
        if(v[i] == w - 1) {
            if(i < n - 1)
                v[i + 1]++;
        }
    }
    cout << "YES\n";
}