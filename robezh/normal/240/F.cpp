#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2


struct node {
    int cnt, st;

    void set_val(int val, int l, int r) {
        if(val == 0) cnt = 0, st = val;
        else cnt = r - l + 1, st = val;
    }

    void merge(node &ls, node &rs) {
        cnt = ls.cnt + rs.cnt;
    }
};

int n, m;
string str;

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].st != -1) {
            if(l < r) {
                int mid = (l + r) / 2;
                dat[ls(x)].set_val(dat[x].st, l, mid);
                dat[rs(x)].set_val(dat[x].st, mid + 1, r);
            }
            dat[x].st = -1;
        }
    }

    void init(int x, int l, int r, char c) {
        if(l == r) {
            dat[x].cnt = (str[l] == c);
            dat[x].st = -1;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid, c);
        init(rs(x), mid + 1, r, c);
        dat[x].st = -1;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    int query(int a, int b, int x = 0, int l = 0, int r = N-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;
        push_down(x, l, r);
        if(l >= a && r <= b) return dat[x].cnt;
        return query(a, b, ls(x), l, mid) + query(a, b, rs(x), mid+1, r);
    }

    void update(int a, int b, int x, int l, int r, int val) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].set_val(val, l, r);
            return ;
        }
        update(a, b, ls(x), l, mid, val);
        update(a, b, rs(x), mid+1, r, val);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

} tr[26];


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> str;
    for(int i = 0; i < 26; i++) tr[i].init(0, 0, n - 1, char('a' + i));
    for(int i = 0; i < m; i++) {
        int l, r, tc = -1; cin >> l >> r; l--, r--;
        vi cnt(26, 0);
        for(int j = 0; j < 26; j++) {
            cnt[j] = tr[j].query(l, r, 0, 0, n - 1);
            if(cnt[j] % 2) {
                if(tc == -1) tc = j;
                else {
                    tc = -2;
                    break;
                }
            }
        }
        if(tc == -2) continue;
        int sl = l, sr = r;
        for(int j = 0; j < 26; j++) {
            if(cnt[j] == 0) continue;
            tr[j].update(l, r, 0, 0, n - 1, 0);
            tr[j].update(sl, sl + cnt[j] / 2 - 1, 0, 0, n - 1, 1);
            tr[j].update(sr - cnt[j] / 2 + 1, sr, 0, 0, n - 1, 1);
            sl += cnt[j] / 2;
            sr -= cnt[j] / 2;
        }
//        cout << sl << " " << sr << " " << tc << endl;
        if(tc != -1) {
            tr[tc].update(sl, sr, 0, 0, n - 1, 1);
        }
    }


    for(int i = 0; i < n; i++) {
        for(int b = 0; b < 26; b++) {
            if(tr[b].query(i, i, 0, 0, n - 1)) {
                cout << (char)('a' + b);
                break;
            }
        }
    }
    cout << endl;
}