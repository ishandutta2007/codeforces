#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, B = 2, INF = (int)1e9, mod = (int)1e9 + 7;

struct state {
    int len, link;
    int next[B];
};

int n;
int psum[N];

bool good(int x) {
    return x != 3 && x != 5 && x != 14 && x != 15;
}

struct SAM {
    const static int MAXLEN = (int)1e5 + 50;
    state st[MAXLEN * 2];
    int sz, last;
    int len = 0;
    int firpos[MAXLEN * 2];
    int dp[MAXLEN * 2];
    int id[MAXLEN * 2];

    void sam_init() {
        len = 0;
        st[0].len = 0;
        st[0].link = -1;
        fill(firpos, firpos + MAXLEN * 2, INF);
        memset(st[0].next, -1, sizeof(st[0].next));
        sz = 1;
        last = 0;
    }

    void sam_extend(int c, int i) {
        len++;
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        firpos[cur] = i;
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

    int next(int i, int mask, int len) {
        for(int b = len - 1; b >= 0; b--) {
            int al = (mask >> b) & 1;
            i = st[i].next[al];
            if(i == -1) return -1;
        }
        return i;
    }

    void sort(int asc) {
        static int cnt[MAXLEN];
        fill(cnt, cnt + len + 1, 0);
        for(int i = 0; i < sz; i++) cnt[st[i].len]++;
        if(asc) for(int i = 1; i <= len; i++) cnt[i] += cnt[i-1];
        else for(int i = len - 1; i >= 0; i--) cnt[i] += cnt[i+1];
        for(int i = 0; i < sz; i++) id[--cnt[st[i].len]] = i;
    }

    void pre() {
        sort(false);
        for(int idx = 0; idx < sz; idx++) {
            int i = id[idx];
            if(st[i].link != -1) firpos[st[i].link] = min(firpos[st[i].link], firpos[i]);
        }
    }

    void calc() {
        pre();
        sort(true);
        dp[0] = 1;
        int res = 0;
        for(int idx = 0; idx < sz; idx++) {
            int i = id[idx];
            for(int mlen = 1; mlen <= 4; mlen++) {
                for(int j = 0; j < (1 << mlen); j++) {
                    if(mlen == 4 && !good(j)) continue;
                    int nx = next(i, j, mlen);
                    if(nx != -1) dp[nx] += dp[i], dp[nx] %= mod;
                }
            }
            psum[firpos[i]] += dp[i];
            psum[firpos[i]] %= mod;
        }
    }


} sam;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sam.sam_init();
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        sam.sam_extend(c - '0', i);
    }
    sam.calc();
    for(int i = 1; i < n; i++) psum[i] += psum[i-1], psum[i] %= mod;
    for(int i = 0; i < n; i++) cout << (psum[i] - 1 + mod) % mod << "\n";

}