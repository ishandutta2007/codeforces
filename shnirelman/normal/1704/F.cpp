#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int M = 1e9 + 7;
//const int M = 32768;
const int N = 5e5 + 13;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int inv(int n) {
    return pow2(n, M - 2);
}

mt19937 rnd(54787);

/*
*/

int dp[N];

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

//    vector<pii> a;
//    for(int i = 0; i < n; i++) {
//        if(i == 0 || s[i] != s[i + 1])
//            a.emplace_back(1, s[i] == 'R' ? 0 : 1);
//        else
//            a.back().f++;
//    }

    int cnt = 0;
    int x0 = 0, x1 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R')
            x0++;
        else
            x1++;
    }

    if(x0 > x1) {
        cout << "Alice" << endl;
        return;
    } else if(x0 < x1) {
        cout << "Bob" << endl;
        return;
    }


//    for(int i = 1000; i < N; i++) {
//        dp[i] = 1;
//    }
//
//    for(int i = 994; i + 34 < N; i++) {
//        dp[i + 12] = dp[i + 16] = dp[i + 20] = dp[i + 30] = dp[i + 34] = 0;
//    }

    for(int i = 0; i < n - 1; ) {
        int cur = 0;
        int j = i + 1;
        while(j < n && s[j] != s[j - 1]) {
            j++;
        }

        cnt ^= dp[j - i - 1];//(j - i) / 2;
//        cout << j - i << endl;
        i = j;
    }

//    cout << "cnt = " << cnt << endl;
//        if(s[i] != s[i + 1])
//            cnt++;

//    cnt %= 2;

    x0 += (cnt != 0);

    cout << (x0 > x1 ? "Alice" : "Bob") << endl;;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = dp[2] = 1;
    for(int i = 3; i < 1000; i++) {
        set<int> st;
        st.insert(dp[i - 2]);
        for(int j = 2; j < i; j++) {
            st.insert(dp[j - 2] ^ dp[i - j - 1]);
        }

        while(st.count(dp[i]))
            dp[i]++;
    }

    for(int i = 1000; i < N; i++) {
        dp[i] = dp[i - 34];
    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}