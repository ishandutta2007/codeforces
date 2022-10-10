#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<array<int, 2>> ed;
vector<int> par[2];
int n;

vector<int> query(int s) {
    cout << "? " << s + 1 << endl;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    return v;
}

void add(int a, int b) {
    ed.insert({min(a, b) + 1, max(a, b) + 1});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    auto v = query(0);
    for(int i = 0; i < n; i++) {
        if(v[i] == 1)
            add(0, i);
        par[(v[i] % 2)].push_back(i);
    }
    if(par[1].size() < par[0].size())
        swap(par[0], par[1]);
    else {
        reverse(par[0].begin(), par[0].end());
        par[0].pop_back();
    }
    for(auto &u : par[0]) {
        auto w = query(u);
        for(int i = 0; i < n; i++) {
            if(w[i] == 1)
                add(u, i);
        }
    }

    cout << "!\n";
    for(auto &[u, v] : ed)
        cout << u << " " << v << '\n';
    cout << flush;
}