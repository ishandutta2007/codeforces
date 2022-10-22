#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)4e5 + 50;

int n;
int a[N];
map<int, int> mp;
int tcnt[N];
int sum = 0;
vector<P> cp;
vector<P> icp;
vector<vector<int> > ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(auto &p : mp) tcnt[p.second]++, sum++;
    int ns = 0;
    int mx = -1, mx_h = -1, mx_w = -1;
    for(int h = 1; h <= n; h++) {
        ns += sum;
        if(ns / h < h) continue;
        int cur_ns = ns / h * h;
        if(cur_ns > mx) {
            mx = cur_ns;
            mx_h = h;
            mx_w = ns / h;
        }
        sum -= tcnt[h];
    }
    ns = mx;
    for(auto &p : mp) {
        int tk = min(min(p.second, mx_h), ns);
        if(tk == mx_h) cp.push_back({p.first, tk});
        else {
            icp.push_back({p.first, tk});
        }
        ns -= tk;
        if(ns == 0) break;
    }
//    cout << mx_h << " " << mx_w << endl;
//    for(auto p : icp) cout << p.first << " " << p.second << endl;
    while(!icp.empty()) cp.push_back(icp.back()), icp.pop_back();


    ans = vector<vector<int> >(mx_h, vector<int>(mx_w, 0));
    for(int j = mx_w - 1; j >= 0; j--) {
        for(int i = 0; i < mx_h; i++) {
            int curj = ((j - i) % mx_w + mx_w) % mx_w;
            if(cp.back().second == 0)
                cp.pop_back();
            ans[i][curj] = cp.back().first;
            cp.back().second--;
        }
    }
    cout << mx << '\n';
    cout << mx_h << " " << mx_w << '\n';
    for(int i = 0; i < mx_h; i++) {
        for(int j = 0; j < mx_w; j++) cout << ans[i][j] << " ";
        cout << '\n';
    }

}