#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
const int N = (int)1e5 + 500, INF = (int)1e9 + 50, M = (int)2e5 + 50;

int n, m, k, q;
int nxt[N], ocu[N];

struct qry {
    int x1, y1, x2, y2, id;
    void norm() {
        x1--, y1--, x2--, y2--;
    }
} qrs[2 * N];

struct P {
    int x, y;
    void norm() {
        x--, y--;
    }
} pt[2 * N];

struct Tree {
    int sum[N * 4], mx[N * 4];


    void init_dat(){
        fill(sum, sum + N * 4, 0);
        fill(mx, mx + N * 4, INF);
    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            sum[x] = 1;
            mx[x] = val;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        sum[x] = sum[lson(x)] + sum[rson(x)];
        mx[x] = max(mx[lson(x)], mx[rson(x)]);
    }

    int get_sum(int a, int b, int x, int l, int r){
        if(r < a || b < l) return 0;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return sum[x];

        int LHS = get_sum(a, b, lson(x), l, mid);
        int RHS = get_sum(a, b, rson(x), mid + 1, r);

        return LHS + RHS;
    }

    int get_mx(int a, int b, int x, int l, int r){
        if(r < a || b < l) return 0;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return mx[x];

        int LHS = get_mx(a, b, lson(x), l, mid);
        int RHS = get_mx(a, b, rson(x), mid + 1, r);

        return max(LHS, RHS);
    }


} tree;

vector<int> solve() {
    tree.init_dat();
    sort(qrs, qrs + q, [](const qry &q1, const qry &q2) {
        return q1.x1 < q2.x1;
    });
    sort(pt, pt + k, [](const P &p1, const P &p2) {
        return p1.x < p2.x;
    });
//    fill(ocu, ocu + N, -1);
//    for(int i = k - 1; i >= 0; i--) {
//        nxt[i] = ocu[pt[i].y];
//        ocu[pt[i].y] = i;
//    }
    int cur_pt = k - 1;
    vector<int> res(q, 0);
    for(int i = q - 1; i >= 0; i--) {
        while(cur_pt >= 0 && pt[cur_pt].x >= qrs[i].x1) {
//            int nx = nxt[cur_pt] == -1 ? INF : pt[nxt[cur_pt]].x;
            tree.update(pt[cur_pt].y, 0, 0, m - 1, pt[cur_pt].x);
            cur_pt--;
        }
//        cout << qrs[i].id << ": " << tree.get_sum(qrs[i].y1, qrs[i].y2, 0, 0, m - 1) << ", " << qrs[i].y2 - qrs[i].y1 + 1 << endl;
        res[qrs[i].id] = tree.get_sum(qrs[i].y1, qrs[i].y2, 0, 0, m - 1) == qrs[i].y2 - qrs[i].y1 + 1
                && tree.get_mx(qrs[i].y1, qrs[i].y2, 0, 0, m - 1) <= qrs[i].x2;
    }
    return res;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k >> q;
    for(int i = 0; i < k; i++) {
        cin >> pt[i].x >> pt[i].y;
        pt[i].norm();
    }
    for(int i = 0; i < q; i++) {
        cin >> qrs[i].x1 >> qrs[i].y1 >> qrs[i].x2 >> qrs[i].y2;
        qrs[i].id = i;
        qrs[i].norm();
    }
    vector<int> res(q, 0);
    for(int swapped = 0; swapped < 2; swapped++) {
        if(swapped) {
            swap(n, m);
            for(int i = 0; i < q; i++) swap(qrs[i].x1, qrs[i].y1), swap(qrs[i].x2, qrs[i].y2);
            for(int i = 0; i < k; i++) swap(pt[i].x, pt[i].y);
        }
        vector<int> cur_res = solve();
        for(int i = 0; i < q; i++) res[i] |= cur_res[i];
    }
    for(int i = 0; i < q; i++) cout << (res[i] ? "YES" : "NO") << "\n";
}