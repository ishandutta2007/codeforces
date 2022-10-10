#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 3e5 + 35;
int fst[MAX], snd[MAX];

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), has;
    for(auto &x : v) {
        cin >> x;
        has.push_back(x);
    }
    sort(has.begin(), has.end());
    auto it = unique(has.begin(), has.end());
    has.erase(it, has.end());
    for(int i = 0; i < n; i++)
        snd[v[i]] = i + 1;
    for(int i = n - 1; i >= 0; i--)
        fst[v[i]] = i + 1;
    int cur = 1, bst = 0;
    for(int i = 1; i < has.size(); i++) {
        if(fst[has[i]] >= snd[has[i - 1]])
            cur++;
        else {
            bst = max(bst, cur);
            cur = 1;
        }
    }
    bst = max(bst, cur);
    cout << has.size() - bst << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
        solve();
}