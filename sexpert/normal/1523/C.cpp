#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        if(i > 0)
            cout << ".";
        cout << v[i];
    }
    cout << '\n';
}

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(v.empty())
            v.push_back(x);
        else {
            if(x == 1) {
                v.push_back(x);
            }
            else {
                while(x != v.back() + 1)
                    v.pop_back();
                v[v.size() - 1]++;
            }
        }
        print(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}