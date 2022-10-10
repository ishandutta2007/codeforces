#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using qry = array<int, 3>;

struct wnode {
    int lo, hi;
    wnode *left, *right;
    vector<int> cleft;
 
    wnode(int *st, int *en, int lo, int hi) : lo(lo), hi(hi) {
        if(st == en || lo == hi) return;
        int mi = (lo + hi)/2;
        auto f = [mi](int x) { return x <= mi; };
        cleft.push_back(0);
        for(auto it = st; it != en; ++it) cleft.push_back(cleft.back() + f(*it));
        auto it = stable_partition(st, en, f);
        left = new wnode(st, it, lo, mi);
        right = new wnode(it, en, mi + 1, hi);
    }
 
    int count(int L, int R, int X, int Y) {
        if(Y < lo || hi < X || Y < X || L > R) return 0;
        if(X <= lo && hi <= Y) return R - L + 1;
        int mi = (lo + hi)/2;
        int izq = cleft[L - 1], der = cleft[R];
        return left->count(izq + 1, der, X, Y) + right->count(L - izq, R - der, X, Y);
    }
};

const int MAXN = 2e5 + 10;

vector<wnode> trees;
int n, m;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(a, -1, sizeof a);

    set<int> guys;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(guys.count(x))
            guys.erase(x);
        else
            guys.insert(x);
    }

    for(int b = 0; b < 18; b++) {
        memset(a, 0, sizeof a);
        for(auto &x : guys)
            a[x] = (x % (1 << (b + 1)) + 1);
        //for(int i = 0; i <= m; i++)
        //    cout << a[i] << " ";
        //cout << endl;
        trees.push_back(wnode(a + 1, a + m + 1, 0, (1 << (b + 1))));
    }

    int q;
    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        //cout << "querying " << L << " " << R << endl;
        bool win_b = true;
        for(int b = 0; b < 18; b++) {
            int mod = (1 << (b + 1));
            int off = L % mod, cnt;
            //cout << "good guys in interval " << off + 1 << " " << off + mod/2 << endl;
            if(off < mod / 2) {
                //cout << "querying " << 1 << " " << off << " and " << off + mod/2 + 1 << " " << mod << " in " << L << " " << R << endl;
                cnt = trees[b].count(L, R, 1, off);
                //cout << cnt << endl;
                cnt += trees[b].count(L, R, off + mod/2 + 1, mod);
                //cnt = trees[b].count(L, R, off + 1, off + mod/2);
                //cout << "querying " << off + 1 << " " << off + mod/2 << endl;
                //cout << cnt << endl;
            }
            else {
                //cout << "querying " << off - mod/2 + 1 << " " << off << endl;
                cnt = trees[b].count(L, R, off - mod/2 + 1, off);
                //cnt = trees[b].count(L, R, off + 1, mod);
                //cnt += trees[b].count(L, R, 1, off - mod/2);
                //cout << "querying " << off + 1 << " " << mod << " and " << 1 << " " << off - mod/2 << endl;
                //cout << cnt << endl;
            }
            if(cnt % 2) {
                win_b = false;
                break;
            }
        }
        cout << (win_b ? 'B' : 'A');
    }
    cout << '\n';
}