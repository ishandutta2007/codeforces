#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 5, B = 26;
const static int MAXLEN = (int)1e5 + 5, LOGN = 21;
typedef long long ll;

struct state {
    int len, link;
    int next[B];
};

int k;

struct SAM {

    state st[MAXLEN * 2];
    int sz, last;
    int cnt[MAXLEN * 2];
    int sum[MAXLEN * 2];
    set<int> S[MAXLEN * 2];
    int idx[MAXLEN * 2];


    void sam_init() {
        st[0].len = 0;
        st[0].link = -1;
        memset(st[0].next, -1, sizeof(st[0].next));
        sz = 1;
        last = 0;
        for(int i = 0; i < MAXLEN * 2; i++) idx[i] = i;
    }

    int sam_extend(int c, int nlast, vector<int> &ids) {
//        cout << "extending with val: " << val << endl;
        last = nlast;
        int cur = sz++;
        for(int id : ids) S[cur].insert(id);
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
        return last;
    }

    int unite(int u, int v) {
        if(S[u].size() > S[v].size()) swap(u, v);
        for(int x : S[u]) S[v].insert(x);
        S[u].clear();
        return v;
    }

    void build() {
        static int a[MAXLEN * 2];
        for(int i = 0; i < sz; i++) a[i] = i;
        sort(a, a + sz, [this](int i, int j){return st[i].len < st[j].len;});

        for(int j = sz - 1; j >= 1; j--) {
            int u = a[j];
            sum[u] = (S[idx[u]].size() >= k) * (st[u].len - st[st[u].link].len);
            idx[st[u].link] = unite(idx[st[u].link], idx[u]);
        }
        for(int j = 1; j < sz; j++) sum[a[j]] += sum[st[a[j]].link];



//        cout << "sz: " << sz << endl;
//        for(int i = 0; i <= sz; i++) {
//            cout << i << " link to " << st[i].link << ", with val " << cnt[i] << endl;
//            cout << "list: ";
//            for(int j =0 ; j < B; j++) cout << st[i].next[j] << " ";
//            cout << endl;
//        }

    }


} sam;

int n, m;
vector<int> tid[N];

struct Trie {
    int nxt[MAXLEN][B];
    vector<int> have[MAXLEN];
    int sz;
    int id[MAXLEN];

    void init() {
        sz = 1;
        memset(nxt, -1, sizeof(nxt));
    }

    void add(string s, int idx) {
        int cur = 0;
        for(char c : s) {
            int &nx = nxt[cur][c - 'a'];
            if(nx == -1) {
                nx = sz++;
            }
            cur = nx;
            tid[idx].push_back(cur);
            have[cur].push_back(idx);
        }
    }

    void build_sam() {
        sam.sam_init();
        queue<int> que;
        id[0] = 0;
        que.push(0);
        while(!que.empty()) {
            int v = que.front(); que.pop();
            for(int i = 0; i < B; i++) {
                if(nxt[v][i] != -1) {
                    id[nxt[v][i]] = sam.sam_extend(i, id[v], have[nxt[v][i]]);
                    que.push(nxt[v][i]);
                }
            }
        }
        sam.build();
    }

} trie;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    trie.init();
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        trie.add(s, i);
    }
    trie.build_sam();
    for(int i = 0; i < n; i++) {
        ll sum = 0;
        for(int id : tid[i]) sum += sam.sum[trie.id[id]];
        cout << sum << " ";
    }


}