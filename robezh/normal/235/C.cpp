#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, B = 26, INF = (int)1e9;

struct state {
    int len, link;
    int next[B];
};

int n;
string str;
string s[N];
int m = 0;

struct SAM {
    const static int MAXLEN = (int)1e6 + 50;
    state st[MAXLEN * 2];
    int sz, last;
    int cnt[MAXLEN * 2];
    int id[MAXLEN * 2];
    int vis[MAXLEN * 2];
    vector<int> vs;

    void sam_init() {
        st[0].len = 0;
        st[0].link = -1;
        memset(st[0].next, -1, sizeof(st[0].next));
        sz = 1;
        last = 0;
    }

    void sam_extend(int c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        cnt[cur] = 1;
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

    void calc(int len) {
        sort(len);
        for(int idx = sz - 1; idx >= 1; idx--) {
            int x = id[idx];
            cnt[st[x].link] += cnt[x];
        }
    }

    int get_ocur(string &s) {
        int len = s.length();
        s += s;
        s.pop_back();
        int cur = 0, curlen = 0;
        int res = 0;
        for(int i = 0; i < 2 * len - 1; i++) {
            while(cur != 0 && st[cur].next[s[i] - 'a'] == -1) cur = st[cur].link, curlen = min(curlen, st[cur].len);
            if(st[cur].next[s[i] - 'a'] != -1) cur = st[cur].next[s[i] - 'a'], curlen++;

            if(i < len - 1) continue;
            while(cur != 0 && min(curlen, st[st[cur].link].len) >= len) cur = st[cur].link, curlen = min(curlen, st[cur].len);
            if(curlen >= len && !vis[cur]) {
                vis[cur] = true;
                vs.push_back(cur);
                res += cnt[cur];
            }
        }
        for(int x : vs) vis[x] = false;
        vs.clear();

        return res;
    }

} sam;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sam.sam_init();
    cin >> str;
    for(char c : str) sam.sam_extend(c - 'a');
    sam.calc(str.length());

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        cout << sam.get_ocur(s[i]) << "\n";
    }



}