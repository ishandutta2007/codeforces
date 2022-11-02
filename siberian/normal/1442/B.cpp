#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int MOD = 998244353;

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

int smart(vector<int> a, vector<int> b) {
    vector<bool> used(a.size() + 1);
    for (auto i : b) {
        used[i] = true;
    }
    vector<bool> pos(a.size());
    for (int i = 0; i < a.size(); ++i) {
        if (used[a[i]]) {
            pos[i] = true;
        }
    }
    vector<int> rpos(a.size() + 1);
    for (int i = 0; i < a.size(); ++i) {
        rpos[a[i]] = i;
    }
    /*cout << "used = " << endl;
    for (auto i : used) {
        cout << i << " ";
    }
    cout << endl;
    cout << "pos = " << endl;
    for (auto i : pos) {
        cout << pos[i] << " ";
    }
    cout << endl;*/
    set<int> myPos;
    for (int i = 0; i < a.size(); ++i) {
        myPos.insert(i);
    }
    int ans = 1;
    for (int i = 0; i < b.size(); ++i) {
        int cnt = 0;
        int posA = rpos[b[i]];
        auto it = myPos.upper_bound(posA);
        if (it != myPos.end() && !pos[*it]) {
            ++cnt;
        }
        --it;
        if (it != myPos.begin()) {
            --it;
            if  (!pos[*it]) {
                ++cnt;
            }
        }
        /*
        if (rpos[b[i]] > 0 && !pos[rpos[b[i]] - 1]) {
            ++cnt;
        }
        if (rpos[b[i]] + 1 < a.size() && !pos[rpos[b[i]] + 1]) {
            ++cnt;
        }*/
        myPos.erase(posA);
        ans = mul(ans, cnt);
    }
    return ans;
}

void solve() {
    int k, n;
    cin >> n >> k;
    vector<int> a(n);

    for (auto& i : a) {
        cin >> i;
    }
    
    vector<int> b(k);
    for (auto& i : b) {
        cin >> i;
    }
    cout << smart(a, b) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}