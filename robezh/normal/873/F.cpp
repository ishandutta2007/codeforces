#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, B = 26, INF = (int)1e9;

struct state {
    int len, link;
    int next[B];
};

int n;
string s, t;
int m = 0;

struct SAM {
    const static int MAXLEN = (int)2e5 + 50;
    state st[MAXLEN * 2];
    int dp[MAXLEN * 2];
    int sz, last;
    int cnt[MAXLEN * 2];
    int id[MAXLEN * 2];

    void sam_init() {
        st[0].len = 0;
        st[0].link = -1;
        memset(st[0].next, -1, sizeof(st[0].next));
        sz = 1;
        last = 0;
    }

    void sam_extend(int c, int good) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        cnt[cur] = good;
        memset(st[cur].next, -1, sizeof(st[cur].next));
        int p = last;
        while(p != -1 && st[p].next[c] == -1) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if(p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if(st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].link = st[q].link;
                while(p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    void sort(int len) {
        static int cnt[MAXLEN];
        fill(cnt, cnt + len + 1, 0);
        for(int i = 1; i < sz; i++) cnt[st[i].len]++;
        for(int i = 2; i <= len; i++) cnt[i] += cnt[i-1];
        for(int i = 1; i < sz; i++) id[cnt[st[i].len]--] = i;
    }

    ll calc(int len) {
        sort(len);
        ll res = 0;
        for(int idx = sz - 1; idx >= 1; idx--) {
            int x = id[idx];
            cnt[st[x].link] += cnt[x];
            res = max(res, 1LL * cnt[x] * st[x].len);
        }
        return res;
    }

} sam;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sam.sam_init();
    cin >> n;
    cin >> s >> t;
    for(int i = 0; i < n; i++) {
        sam.sam_extend(s[i] - 'a', !(t[i] - '0'));
    }
    cout << sam.calc(n) << endl;

}