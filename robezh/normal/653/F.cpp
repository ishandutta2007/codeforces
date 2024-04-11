#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 50, B = 2, LOGN = 20;
typedef long long ll;
const int INF = (int)1e9;

struct state {
    int len, link;
    int next[B];
};

int n;
string str;
int sp[LOGN][N];

struct SAM {
    const static int MAXLEN = (int)5e5 + 50;
    state st[MAXLEN * 2];
    int sz, last;
    int pos[MAXLEN * 2], cnt[MAXLEN * 2];
    ll ans[MAXLEN * 2];

    void sam_init() {
        fill(pos, pos + MAXLEN * 2, -INF);
        st[0].len = 0;
        st[0].link = -1;
        memset(st[0].next, -1, sizeof(st[0].next));
        sz = 1;
        last = 0;
    }

    void sam_extend(int c, int idx) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
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
        pos[last] = idx;
        cnt[last]++;
    }

    ll calc() {
        ll res = 0;

        vector<int> idx(sz, 0);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [this](const int i, const int j) {
            return st[i].len > st[j].len;
        });
        for(int i : idx) {
            if(st[i].link != -1) {
                pos[st[i].link] = max(pos[st[i].link], pos[i]);
                cnt[st[i].link] += cnt[i];
            }
        }
        reverse(idx.begin(), idx.end());
        for(int i : idx) {
            int cur_i = pos[i];
//            cout << "----" << endl;
            if(cur_i == -INF) continue;
//            cout << i << " " << pos[i] << " " << st[i].len << endl;
            for(int lg = LOGN - 1; lg >= 0; lg--) {
                if(sp[lg][cur_i] >= pos[i] - st[i].len) {
                    ans[i] += (1 << lg);
                    cur_i = sp[lg][cur_i];
                }
            }
//            cout << "oans = " << ans[i] << endl;

            res += ans[i];
            if(st[i].link != -1) {
                res -= ans[st[i].link];
//                cout << "link to " << st[i].link << endl;
            }

//            cout << "dans = " << ans[i] << endl;
        }
        return res;
    }


} sam;


int dp[N];

int main() {
    cin >> n;
    cin >> str;

    str = " " + str;
    sam.sam_init();
    for(int i = 1; i <= n; i++) {
        if(str[i] == '(') sam.sam_extend(1, -INF);
        else sam.sam_extend(0, i);
    }
    dp[0] = -1;
    sp[0][0] = -1;
    for(int i = 1; i <= n; i++) {
        if(str[i] == '(' || i == 1) dp[i] = sp[0][i] = -1;
        else if(str[i-1] == ')') {
            if(dp[i-1] >= 1 && str[dp[i-1]] == '(') {
                int la = dp[i-1] - 1;
                sp[0][i] = la;
                dp[i] = (dp[la] == -1 ? la : dp[la]);
            }
            else dp[i] = sp[0][i] = -1;
        }
        else {
            int la = i - 2;
            sp[0][i] = la;
            dp[i] = (dp[la] == -1 ? la : dp[la]);
        }
    }

//    for(int i = 1; i <= n; i++) cout << dp[i] << " ";
//    cout << endl;
//    for(int i = 1; i <= n; i++) cout << sp[0][i] << " ";
//    cout << endl;

    for(int lg = 1; lg < LOGN; lg++) {
        for(int i = 0; i <= n; i++) {
            if(sp[lg-1][i] == -1) sp[lg][i] = -1;
            else sp[lg][i] = sp[lg-1][sp[lg-1][i]];
        }
    }
    cout << sam.calc() << endl;

}