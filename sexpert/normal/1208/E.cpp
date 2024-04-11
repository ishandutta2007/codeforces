#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1e6 + 5;
ll swp[MAX], ans[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> v(m);
        for(auto &x : v)
            cin >> x;
        if(w >= 2*m) {
            int pmx = 0;
            for(int j = 0; j < m; j++) {
                pmx = max(pmx, v[j]);
                int can = pmx;
                if(w - 1 - j >= m)
                    can = max(can, 0);
                ans[j] += (ll)can;
            }
            int smx = 0;
            for(int j = w - 1; j >= w - m; j--) {
                smx = max(smx, v[j - w + m]);
                int can = smx;
                if(j >= m)
                    can = max(can, 0);
                ans[j] += (ll)can;
            }
            if(m <= w - m - 1) {
                pmx = max(pmx, 0);
                swp[m] += pmx;
                swp[w - m] -= pmx;
            }
        }
        else {
            v.resize(w);
            for(int i = m; i < w; i++)
                v[i] = -1000000005;
            int k = w - m + 1;
            vector<int> pls(w);
            deque<ii> window;
            for(int i = 0; i < w; i++) {
                while(window.size() && v[i] >= window.back().first)
                    window.pop_back();
                while(window.size() && window.front().second <= i - k)
                    window.pop_front();
                window.push_back({v[i], i});
                pls[i] = window.front().first;
            }
            for(int i = 0; i < w - m; i++)
                pls[i] = max(pls[i], 0);
            for(int i = w - 1; i >= m; i--)
                pls[i] = max(pls[i], 0);
            for(int i = 0; i < w; i++)
                ans[i] += pls[i];
        }
    }
    ll cur = 0;
    for(int i = 0; i < w; i++) {
        cur += swp[i];
        ans[i] += cur;
    }
    for(int i = 0; i < w; i++)
        cout << ans[i] << " ";
    cout << '\n';
}