#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

// #define LOCAL

#ifdef LOCAL

vector<int> q;
vector<int> p;
// int cnt = p.size() * 2;
int cnt;

#endif

int query(int pos) {
    #ifdef LOCAL
        // assert(--cnt >= 0);
    #endif
    cout << "? " << pos + 1 << endl;
    #ifdef LOCAL
        cerr << "curQ = " << endl;
        for (auto i : q) {
            cerr << i << " ";
        }
        cerr << endl;
        int ans = q[pos];
        vector<int> nq(q.size());
        for (int i = 0; i < q.size(); ++i) {
            nq[i] = q[p[i]];
        }
        q = nq;
        return ans;
    #else
        int ans;
        cin >> ans;
        return ans - 1;
    #endif
}

void outAns(vector<int> ans) {
    cout << "!";
    for (auto i : ans) {
        cout << " " << i + 1;
    }
    cout << endl;
    #ifdef LOCAL
        assert(ans == p);
    #endif
    // exit(0);
}

void myRotate(vector<int>& a, int cnt) {
    ++cnt;
    cnt %= a.size();
    cnt = a.size() - cnt;
    vector<int> answer;
    for (int i = cnt; i < a.size(); ++i) {
        answer.push_back(a[i]);
    }
    for (int i = 0; i < cnt; ++i) {
        answer.push_back(a[i]);
    }
    a = answer;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);

    int t;
    cin >> t;
    while (t--) {

    int n;
    #ifdef LOCAL
        n = (ull)rnd() % 10 + 2;
        p.assign(n, 0);
        iota(all(p), 0);
        shuffle(all(p), rnd);
        cerr << "p = " << endl;
        for (auto i : p) {
            cerr << i << " ";
        }
        cerr << endl;
        cnt = 2 * n;
        q.assign(n, 0);
        iota(all(q), 0);
    #else
        cin >> n;
    #endif
    vector<int> ans(n);
    vector<bool> used(n, false);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        vector<int> have;

        int cur = query(i);
        while (!used[cur]) {
            have.push_back(cur);
            used[cur] = true;
            cur = query(i);
        }

        vector<int> pos = have;
        myRotate(pos, cnt);
        
        cerr << "have = " << endl;
        for (auto i : have) {
            cerr << i << " ";
        }
        cerr << endl;
        cerr << "pos = " << endl;
        for (auto i : pos) {
            cerr << i << " ";
        }
        cerr << endl;
        for (int j = 0; j < pos.size(); ++j) {
            ans[pos[j]] = have[j];
        }
    }
    outAns(ans);
    }
    return 0;
}