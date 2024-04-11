#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1005;
int pr[MAX], cnt;

void solve() {
    int n;
    cin >> n;
    map<int, int> used;
    int p = 1;
    vector<int> ans;
    while(n--) {
        int x;
        cin >> x;
        if(!used[pr[x]])
            used[pr[x]] = p++;
        ans.push_back(used[pr[x]]);
    }
    cout << used.size() << '\n';
    for(auto x : ans)
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int p = 2; p < MAX; p++) {
        if(pr[p])
            continue;
        ++cnt;
        for(int q = p; q < MAX; q += p)
            if(!pr[q])
                pr[q] = cnt;
    }
    int t;
    cin >> t;
    while(t--)
        solve();
}