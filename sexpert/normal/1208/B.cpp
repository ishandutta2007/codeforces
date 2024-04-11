#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    for(int k = 0; k <= n - 1; k++) {
        map<int, int> ct;
        for(int i = 0; i < n; i++)
            ct[v[i]]++;
        for(int i = 0; i < k; i++) {
            ct[v[i]]--;
            if(!ct[v[i]])
                ct.erase(v[i]);
        }
        for(int i = k; i < n; i++) {
            if(ct.size() == n - k) {
                cout << k << '\n';
                return 0;
            }
            ct[v[i]]--;
            ct[v[i - k]]++;
            if(ct[v[i]] == 0)
                ct.erase(v[i]);
        }
        if(ct.size() == n - k) {
            cout << k << '\n';
            return 0;
        }
    }
}