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

const int INF = 1e9 + 228;

struct StackMin{
    vector<int> st;
    vector<int> minVal;
    StackMin() {}
    void push(int x) {
        st.push_back(x);
        minVal.push_back(x);
        if (minVal.size() > 1) {
            chkmin(minVal[minVal.size() - 1], minVal[minVal.size() - 2]);
        }
    }
    void pop() {
        st.pop_back();
        minVal.pop_back();
    }
    int size() {
        return st.size();
    }
    int getMin() {
        if (minVal.size() == 0) return INF;
        return minVal.back();
    }
    int getVal() {
        return st.back();
    }
};

struct QueueMin{
    // vector<int> a;
    StackMin top, bottom;
    QueueMin() {}
    void push(int x) {
        // a.push_back(x);
        top.push(x);
    }
    void relax() {
        if (bottom.size() > 0) return;
        while (top.size() > 0) {
            bottom.push(top.getVal());
            top.pop();
        }
    }
    void pop() {
        // a.erase(a.begin());
        relax();
        bottom.pop();
    }
    int getMin() {
        if (top.size() + bottom.size() == 0) return INF;
        // return *min_element(all(a));
        return min(top.getMin(), bottom.getMin());
    }
    int size() {
        return top.size() + bottom.size();
    }
};

const int M = 1e5 + 10;

int n, m;
int dp[M];

void build() {
    fill(dp, dp + m + 1, INF);
    dp[0] = 0;
}

void relax1(int pos, int myX, int y, int t) {
    // cerr << "relax1 = " << pos << " " << myX << " " << y << endl;
    while (pos + myX <= m) {
        pos += myX;
    }
    QueueMin q;
    int L = pos - myX;
    while (pos >= 0) {
        if (q.size() > 0) q.pop();
        while (L >= 0 && q.size() + 1 <= y) {
            q.push(dp[L]);
            L -= myX;
        }
        // cerr << "pos = " << pos << " q.getMin() = " << q.getMin() << endl;
        if (q.getMin() != INF) {
            chkmin(dp[pos], t);
        }
        pos -= myX;
    }
}

int myPos[M];
int topPos = 0;

bool used[M];

int getNxt(int pos, ll x) {
    return (pos * x + 99999) / 100000;
}

void relax2(int pos, ll x, int y, int t) {
    topPos = 0;
    while (pos <= m) {
        myPos[topPos++] = pos;
        used[pos] = true;
        pos = getNxt(pos, x);
    }
    if (topPos <= 1) return;
    // cerr << "pos = " << pos << " x = " << x << " y = " << y << endl;
    // cerr << "myPos = " << endl;
    // for (int i = 0; i < topPos; ++i) {
    //     cerr << myPos[i] << " ";
    // }
    // cerr << endl;
    QueueMin q;
    int L = topPos - 2;
    pos = topPos - 1;
    while (pos >= 0) {
        if (q.size() > 0) q.pop();
        while (L >= 0 && q.size() + 1 <= y) {
            q.push(dp[myPos[L]]);
            --L;
        }
        // cerr << "myPos = " << myPos[pos] << " q.getMin() = " << q.getMin() << endl;
        if (q.getMin() != INF) {
            chkmin(dp[myPos[pos]], t);
        }
        // cerr << "dp[12] = " << dp[12]<< endl;
        --pos;
    }
}

void process(int ti) {
    fill(used, used + m + 1, false);
    int t, y;
    ll x;
    cin >> t >> x >> y;
    if (t == 1) {
        int myX = (x + 99999) / 100000;
        for (int mod = 0; mod < myX; ++mod) {
            relax1(mod, myX, y, ti);
        }
    } else if (t == 2) {
        for (int pos = 1; pos <= m; ++pos) {
            if (used[pos]) continue;
            relax2(pos, x, y, ti);
        }
    } else {
        assert(false);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m;
    build();
    for (int i = 0; i < n; ++i) {
        process(i + 1);
        // for (int i = 1; i <= m; ++i) {
        // if (dp[i] == INF) {
        //     cout << "-1 ";
        // } else {
        //     cout << dp[i] << " ";
        // }
        // }
        // cout << "\n";
        
    // return 0;    
    }
    for (int i = 1; i <= m; ++i) {
        if (dp[i] == INF) {
            cout << "-1 ";
        } else {
            cout << dp[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}