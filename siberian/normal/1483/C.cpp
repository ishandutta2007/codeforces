#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll
const int N = 3e5 + 10;
int n;
int h[N], b[N];
int dp[N];

const int INF = -1e18;

struct Item{
    int ans, l, r;
    int getAns() const {
        int myAns = INF;
        if (r - l + 1 > 1) {
            chkmax(myAns, ans + b[r]);
        }
        if (l > 0) {
            chkmax(myAns, dp[l - 1] + b[r]);
        } else {
            chkmax(myAns, b[r]);
        }
        return myAns;
    }
};

bool needMerge(const Item& a, const Item& b) {
    return h[a.r] > h[b.r];
}

Item merge(const Item& L, const Item& R) {
    Item ans;
    ans.ans = max({L.ans, dp[L.r], R.ans});
    ans.l = L.l;
    ans.r = R.r;
    return ans;
}

vector<Item> st;
vector<int> ansMax;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    dp[0] = b[0];
    st.push_back({INF, 0, 0});
    ansMax.push_back(st.back().getAns());
    for (int i = 1; i < n; ++i) {
        st.push_back({INF, i, i});
        ansMax.push_back(st.back().getAns());
        if (ansMax.size() > 1) {
            chkmax(ansMax[ansMax.size() - 1], ansMax[ansMax.size() - 2]);
        }
        while (st.size() > 1 && needMerge(st[st.size() - 2], st[st.size() - 1])) {
            auto add = merge(st[st.size() - 2], st[st.size() - 1]);
            st.pop_back();
            st.pop_back();
            ansMax.pop_back();
            ansMax.pop_back();
            st.push_back(add);
            ansMax.push_back(st.back().getAns());
            if (ansMax.size() > 1) {
                chkmax(ansMax[ansMax.size() - 1], ansMax[ansMax.size() - 2]);
            }
        }
        dp[i] = ansMax.back();
    }
    cout << dp[n - 1] << endl;
    return 0;
}