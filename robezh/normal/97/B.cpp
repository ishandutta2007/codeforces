#include <bits/stdc++.h>
using namespace std;

const int N = 10050, E9 = (int)1e9;
typedef pair<int, int> P;

int n;
set<P> ans;
P p[N];

void solve(int l, int r) {
    if(l > r) return ;
    int mid = (l + r) / 2;
    int x = p[mid].first;
    for(int j = l; j <= r; j++) ans.insert({x, p[j].second});
    solve(l, mid - 1);
    solve(mid + 1, r);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    solve(0, n - 1);
    cout << ans.size() << "\n";
    for(auto p : ans) cout << p.first << " " << p.second << "\n";

}