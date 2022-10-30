#include <bits/stdc++.h>
using namespace std;

#define N 1000020

int n, k, a[N], prv[N], nxt[N];

stack <int> st;

const int mod = 1e9 + 7;

inline int func(int l) {
    int t = l / (k - 1);
    return ((1ll * l * t - 1ll * t * (t + 1) / 2 * (k - 1)) % mod + mod) % mod;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    while (!st.empty()) st.pop();
    st.push(0);
    for (int i = 1; i <= n; i ++) {
        while (st.top() && a[st.top()] < a[i]) st.pop();
        prv[i] = st.top(), st.push(i);
    }
    while (!st.empty()) st.pop();
    st.push(n + 1);
    for (int i = n; i; i --) {
        while (st.top() <= n && a[st.top()] <= a[i]) st.pop();
        nxt[i] = st.top(), st.push(i);
    }
    int rlt = 0;
    for (int i = 1; i <= n; i ++) {
        rlt = (rlt + (2ll * mod + func(nxt[i] - prv[i] - 1) - func(nxt[i] - i - 1) - func(i - prv[i] - 1)) % mod * a[i]) % mod;
    }
    printf("%d\n", rlt);
}