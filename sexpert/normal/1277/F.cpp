#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 4e5 + 10;
int uwu[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> cnt;
    for(auto &x : v) {
        cin >> x;
        cnt[x]++;
    }
    for(auto [x, y] : cnt)
        uwu[y]++;
    int abv = n, sub = 0;
    int br = 0, bc = 0;
    for(int w = n; w >= 1; w--) {
        abv -= sub;
        sub += uwu[w];
        if(abv < (ll)w * w)
            continue;
        int h = abv/w;
        if(w * h > br * bc) {
            br = w;
            bc = h;
        }
    }
    cout << br * bc << '\n';
    cout << br << " " << bc << '\n';
    vector<pair<int, int>> pas;
    vector<vector<int>> ans(br, vector<int>(bc));
    for(auto &[x, y] : cnt) {
        y = min(y, br);
        pas.push_back({y, x});
    }
    sort(pas.rbegin(), pas.rend());
    int x = 0, y = 0, cur = 0;
    for(auto &p : pas) {
        while(p.first && cur < br * bc) {
            ans[x][y % bc] = p.second;
            x++;
            y++;
            p.first--;
            if(x == br) {
                y -= x - 1;
                x = 0;
            }
            cur++;
        }
    }
    for(int i = 0; i < br; i++) {
        for(int j = 0; j < bc; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}