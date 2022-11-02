#include <bits/stdc++.h>
 
using namespace std;

struct state {
    int next[20];
    int go[20];
    int link;
    int p;
    int pch;
    int add;
    int sum;

    state() {
        memset(next, 255, sizeof(next));
        memset(go, 255, sizeof(go));
        link = -1;
        p = -1;
        pch = -1;
        add = 0;
        sum = -1;
    }
} states[202];

int link(int);

int go(int st, int d) {
    if (states[st].go[d] == -1) {
        if (states[st].next[d] != -1) {
            states[st].go[d] = states[st].next[d];
        } else {
            if (st == 0) {
                states[st].go[d] = 0;
            } else {
                states[st].go[d] = go(link(st), d);
            }
        }
    }
    return states[st].go[d];
}

int link(int st) {
    if (states[st].link == -1) {
        if (st == 0 || states[st].p == 0) {
            states[st].link = 0;
        } else {
            states[st].link = go(link(states[st].p), states[st].pch);
        }
    }
    return states[st].link;
}

int getSum(int st) {
    if (states[st].sum == -1) {
        if (st == 0) {
            states[st].sum = states[st].add;
        } else {
            states[st].sum = states[st].add + getSum(link(st));
        }
    }
    return states[st].sum;
}

int sz = 1;

void add(const vector <int> digits, int value) {
    int cur = 0;
    for (int v : digits) {
        if (states[cur].next[v] == -1) {
            states[sz].p = cur;
            states[sz].pch = v;
            states[cur].next[v] = sz++;
        }
        cur = states[cur].next[v];
    }
    states[cur].add += value;
}

const int mod = 1000000007;

int dp[222][222][555];

int m;

int solve(int st, int len, int k) {
    if (k < 0) {
        return 0;
    }
    if (len == 0) {
        return 1;
    }
    //cerr << st << " " << len << " " << k << endl;
    int & cur = dp[st][len][k];
    if (cur == -1) {
        cur = 0;
        long long res = 0;
        for (int i = 0; i < m; ++i) {
            int nSt = go(st, i);
            res = (res + solve(nSt, len - 1, k - getSum(nSt)));
        }
        cur = res % mod;
    }
    return cur;
}

int solve(const vector <int> digits, int k) {
    long long res = 0;
    for (int len = 1; len < (int)digits.size(); ++len) {
        for (int j = 1; j < m; ++j) {
            int nSt = go(0, j);
            res = (res + solve(nSt, len - 1, k - getSum(nSt)));
        }
        
    }
    int st = 0;

    for (int i = 0; i < (int)digits.size(); ++i) {
        int mi = i ? 0 : 1;
        for (int j = mi; j < digits[i]; ++j) {
            int nSt = go(st, j);
            res = (res + solve(nSt, digits.size() - i - 1, k - getSum(nSt)));
        }
        st = go(st, digits[i]);
        k -= getSum(st);
    }
    return res % mod;
}


int main() {
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    //freopen("2strings.in", "r", stdin);
    //freopen("2strings.out", "w", stdout);
#endif
    memset(dp, 255, sizeof(dp));
    ios_base::sync_with_stdio(false);
    
    int n, k;

    cin >> n >> m >> k;

    int len;
    cin >> len;
    

    vector <int> l(len);

    for (int i = 0; i < len; ++i) {
        cin >> l[i];
    }

    cin >> len;

    vector <int> r(len);

    for (int i = 0; i < len; ++i) {
        cin >> r[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> len;
        vector <int> digits(len);
        for (int i = 0; i < len; ++i) {
            cin >> digits[i];
        }
        int value;
        cin >> value;
        add(digits, value);
    }
    int carry = 1;
    for (int i = (int)r.size() - 1; i >= 0; --i) {
        r[i] += carry;
        if (r[i] >= m) {
            carry = 1;
            r[i] -= m;
        } else {
            carry = 0;
        }
    }
    if (carry) {
        reverse(r.begin(), r.end());
        r.push_back(1);
        reverse(r.begin(), r.end());
    }

    cout << (solve(r, k) + mod - solve(l, k)) % mod << endl;

    return 0;
}