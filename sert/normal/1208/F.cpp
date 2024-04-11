#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
// const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void update(int &m1, int &m2, int x) {
    if (x > m2 && x != m1) swap(x, m2);
    if (m2 > m1) swap(m1, m2);
}

bool kk(const vector<int> &m2, const vector<int> &a, int msk) {
    for (int i = 0; i < (int)a.size(); i++) {
        int nid = (msk ^ (a[i] & msk));
        if (m2[nid] > i) return true;
    }
    return false;
}

int stress(vector<int> a) {
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                ans = max(ans, (a[i] | (a[j] & a[k])));
            }
        }
    }
    return ans;
}

int solve(vector<int> aa = {}, bool dbg = false) {
    int KK = 21;
    int n;
    vector<int> a;        
    if (dbg) {
        n = aa.size();
        a = aa;
    } else {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
    }
    vector<int> m1(1 << KK, -1), m2(1 << KK, -1);

    for (int i = 0; i < n; i++) {
        update(m1[a[i]], m2[a[i]], i);
    }

    for (int msk = (1 << KK) - 1; msk > 0; msk--) {
        for (int i = 0; i < KK; i++) {
            if ((msk & (1 << i)) == 0) continue;
            int msk2 = (msk ^ (1 << i));
            update(m1[msk2], m2[msk2], m1[msk]);
            update(m1[msk2], m2[msk2], m2[msk]);
        }
    }    

    int msk = 0;
    for (int i = KK - 1; i >= 0; i--) {
        msk += (1 << i);
        if (!kk(m2, a, msk)) {
            msk -= (1 << i);
        }
    }
    if (!D) cout << msk << "\n";
    return msk;
}

int main() {
    solve();
    return 0;
#ifdef MADE_BY_SERT
    D = true;
#endif
    int it = 0;
    while (clock() < CLOCKS_PER_SEC * 2.3) {
        int n = 5;
        it++;
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = rand() % 8;

        int s1 = solve(a, true);
        int s2 = stress(a);

        if (s1 != s2) {
            cout << s1 << " " << s2 << "\n";
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
            cout << it << "\n";
            return 0;
        }
    }
    cout << it << "\n";
}