#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

vector<ii> segs, bads;
int ans[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        segs.push_back({i, i});
    while(m--) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 0)
            bads.push_back({l, r});
        else
            segs.push_back({l, r});
    }
    sort(segs.begin(), segs.end());
    vector<ii> reduced;
    for(auto seg : segs) {
        if(reduced.empty() || seg.first > reduced.back().second)
            reduced.push_back(seg);
        else
            reduced.back().second = max(reduced.back().second, seg.second);
    }

    for(auto b : bads) {
        for(auto p : reduced) {
            if(p.first <= b.first && b.second <= p.second) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    int cur = 1;
    for(int i = reduced.size() - 1; i >= 0; i--) {
        int l = reduced[i].first, r = reduced[i].second;
        for(int j = l; j <= r; j++) {
            ans[j] = cur;
            cur++;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}