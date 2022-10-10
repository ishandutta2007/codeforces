#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 10;
int ans[MAXN], n, m, cur = 0;
vector<ii> v;

void solve() {
    sort(v.begin(), v.end());
    int po = 0, cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        auto p = v[i];
        if(po != p.first) {
            for(int j = i - 1; j >= 0; j--) {
                if(v[j].first != po)
                    break;
                ans[v[j].second] = cur;
            }
            if(po != 0)
                cur += 1 + cnt/2;
            cur += p.first - po;
            po = p.first;
            cnt = 0;
        }
        cnt++;
    }
    for(int j = v.size() - 1; j >= 0; j--) {
        if(v[j].first != po)
            break;
        ans[v[j].second] = cur;
    }
    cur += 1 + cnt/2;
    cur += po;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;
        v.push_back({x, i});
        if(i%m == m - 1 || i == n - 1) {
            cur = max(cur, t);
            solve();
            v.clear();
        }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}