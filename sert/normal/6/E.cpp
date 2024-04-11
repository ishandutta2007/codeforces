#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 41;

struct Stack {
    vector<int> mn, mx, a;
    Stack() { mn.clear(); mx.clear(); a.clear(); }
    void push(int x) {
        mn.push_back(mn.empty() ? x : min(mn.back(), x));
        mx.push_back(mx.empty() ? x : max(mx.back(), x));
        a.push_back(x);
    }
    int pop() { int res = a.back(); mn.pop_back(); mx.pop_back(); a.pop_back(); return res; }
    int getTop() { return a.back(); }
    bool empty() const { return a.empty(); }
    int getMax() const { return mx.empty() ? -INF : mx.back(); }
    int getMin() const { return mn.empty() ? INF : mn.back(); }
};

struct Queue {
    Stack s1, s2;
    void push(int x) { s1.push(x); }
    int pop() {
        if (s2.empty())
            while (!s1.empty())
                s2.push(s1.pop());
        return s2.pop();
    }

    int getMin() const { return min(s1.getMin(), s2.getMin()); }
    int getMax() const { return max(s1.getMax(), s2.getMax()); }
    int getDif() const { return getMax() - getMin(); }
};

void solve() {
    Queue q;
    int n, t;
    cin >> n >> t;
    vector<int> a(n); for (int &x : a) cin >> x;
    vector<int> ans(n);

    int cur = 0;
    for (int i = 0; i < n; i++) {
        while (cur < n && max(q.getMax(), a[cur]) - min(q.getMin(), a[cur]) <= t) {
            q.push(a[cur++]);
            //cout << i << " " << i + cur << " " << q.getMin() << " " << q.getMax() << "\n";
        }
        ans[i] = cur - i;
        q.pop();
    }
    int mxAns = *max_element(ans.begin(), ans.end());
    int mxCnt = count(ans.begin(), ans.end(), mxAns);
    cout << mxAns << " " << mxCnt << "\n";
    for (int i = 0; i < n; i++) {
        if (ans[i] == mxAns) {
            cout << i + 1 << " " << i + mxAns << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 3;
#endif
    while (t--) {
        solve();
    }
}