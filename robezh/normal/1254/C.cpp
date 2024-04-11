#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

ll ask_area(int i, int j, int k) {
    cout << 1 << " " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    fflush(stdout);
    ll res;
    cin >> res;
    return res;
}

int ask_sign(int i, int j, int k) {
    cout << 2 << " " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    fflush(stdout);
    int x; cin >> x;
    return x;
}

const int N = 1005;

int n;
int a, b;
vector<pli> v[2];
vector<int> res[2][2];

int main() {
    cin >> n;
    for(int i = 2; i < n; i++) {
        ll cur_area = ask_area(0, 1, i);
        int idx = (ask_sign(i, 0, 1) == 1) ? 0 : 1;
        v[idx].push_back({cur_area, i});
    }
    for(int idx = 0; idx < 2; idx++) sort(v[idx].begin(), v[idx].end());
    for(int idx = 0; idx < 2; idx++) {
        for(int j = 0; j + 1 < v[idx].size(); j++) {
            int nxt_idx = (ask_sign(0, v[idx][j+1].second, v[idx][j].second) == 1) ? 0 : 1;
            res[idx][nxt_idx].push_back(v[idx][j].second);
        }
        if(!v[idx].empty()) res[idx][0].push_back(v[idx].back().second);
        while(!res[idx][0].empty()) {
            res[idx][1].push_back(res[idx][0].back());
            res[idx][0].pop_back();
        }
    }
    cout << "0 1 ";
    for(int x : res[1][1]) cout << x + 1 << " ";
    cout << "2 ";
    for(int x : res[0][1]) cout << x + 1 << " ";


}