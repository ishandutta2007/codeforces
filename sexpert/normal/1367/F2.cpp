#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    map<int, int> conv;
    vector<int> sv = v;
    int cur = 0;
    sort(sv.begin(), sv.end());
    sv.erase(unique(sv.begin(), sv.end()), sv.end());
    for(int i = 0; i < sv.size(); i++)
        conv[sv[i]] = i;
    for(auto &x : v)
        x = conv[x];
    
    int m = sv.size();
    vector<vector<int>> ps(m);
    vector<int> l(m), r(m);
    for(int i = 0; i < n; i++) {
        r[v[i]] = i;
        ps[v[i]].push_back(i);
    }
    for(int i = n - 1; i >= 0; i--)
        l[v[i]] = i;
    
    
    int L = 0, R = 0, sz = ps[0].size();
    int ans = sz;
    while(L < m) {
        while(R + 1 < m && r[R] < l[R + 1]) {
            R++;
            sz += ps[R].size();
        }
        if(R + 1 < m && r[R + 1] > r[R]) {
            int S = ps[R + 1].size();
            int lo = 0, hi = S - 1;
            while(lo < hi) {
                int mi = (lo + hi)/2;
                if(ps[R + 1][mi] > r[R])
                    hi = mi;
                else
                    lo = mi + 1;
            }
            sz += S - hi;
        }
        if(L - 1 >= 0 && l[L - 1] < l[L]) {
            int S = ps[L - 1].size();
            int lo = 0, hi = S - 1;
            while(lo < hi) {
                int mi = (lo + hi + 1)/2;
                if(ps[L - 1][mi] < l[L])
                    lo = mi;
                else
                    hi = mi - 1;
            }
            sz += lo + 1;
        }
        //cout << L << " " << R << " " << sz << endl;
        ans = max(ans, sz);
        L = R + 1;
        R = L;
        if(L < m)
            sz = ps[L].size();
    }
    for(int i = 0; i + 1 < m; i++) {
        for(int j = 0; j < ps[i].size(); j++) {
            int R = ps[i][j];
            if(r[i + 1] < R)
                continue;
            int S = ps[i + 1].size();
            int lo = 0, hi = S - 1;
            while(lo < hi) {
                int mi = (lo + hi)/2;
                if(ps[i + 1][mi] > R)
                    hi = mi;
                else
                    lo = mi + 1;
            }
            ans = max(ans, j + 1 + S - hi);
        }
    }
    cout << n - ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}