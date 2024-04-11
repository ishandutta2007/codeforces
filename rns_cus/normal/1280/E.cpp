#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int r, nxt[N], tot, ans[N];
char s[N];

int solve(int l, int r) {
    if (l == r) return 1;
    int m = l;
    if (s[l] == '(') m = nxt[l];
    if (m == r) return solve(l + 1, r - 1);
    ans[l] = solve(l, m);
    m += 2;
    char c = s[m];
    m += 2;
    ans[m] = solve(m, r);
    if (c == 'P') return ans[l] + ans[m];
    else return min(ans[l], ans[m]);
}

vector <int> v;

void calc(int l, int r) {
    if (l == r) return v.push_back(l), void();
    int m = l;
    if (s[l] == '(') m = nxt[l];
    if (m == r) return calc(l + 1, r - 1), void();
    m += 2;
    if (s[m] == 'P') return calc(l, m - 2), calc(m + 2, r);
    else ans[l] < ans[m+2] ? calc(l, m - 2) : calc(m + 2, r);
}



bool vis[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d ", &r), gets(s + 1);
        int n = strlen(s + 1);
        stack <int> st;
        for (int i = 1; i <= n; i ++) {
            if (s[i] == ')') nxt[st.top()] = i, st.pop();
            else if (s[i] == '(') st.push(i);
        }
        tot = solve(1, n); v.clear();
        calc(1, n);
        typedef long long ll;
        int m = 0; ll ans = (ll)v.size() * r;
        for (int i = 1; i <= n; i ++) vis[i] = 0;
        for (auto x : v) vis[x] = 1;
        printf("REVOLTING");
        for (int i = 1; i <= n; i ++) if (s[i] == '*') {
            printf(" %I64d", vis[i] ? ans : 0);
        }
        puts("");
    }

    return 0;
}