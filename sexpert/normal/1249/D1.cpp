#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

bool out[205];
int cnt[205];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    vector<ii> segs;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        for(int i = l; i <= r; i++)
            cnt[i]++;
        segs.push_back({l, r});
    }
    vector<int> ans;
    for(int p = 1; p <= 200; p++) {
        while(cnt[p] > k) {
            int be = -1;
            for(int i = 0; i < n; i++) {
                if(out[i] || segs[i].second < p || segs[i].first > p)
                    continue;
                if(be == -1 || segs[i].second > segs[be].second)
                    be = i;
            }
            ans.push_back(be + 1);
            out[be] = 1;
            for(int j = segs[be].first; j <= segs[be].second; j++)
                cnt[j]--;
        }
    }
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x << " ";
    cout << endl;
}