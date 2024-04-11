#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;
const int N = 300010;
int n , a[N];
struct TreeNode {
    int tag;
    int color[8];
    int count[8];
};

struct stree {
    int K;
    TreeNode T[N << 2];

    TreeNode pushUp(TreeNode A, const TreeNode &B) {
        for (int i = 0; i < K; ++ i) {
            if (B.count[i]) {
                int j, mn = 0;
                for (j = 0; j < K; ++ j) {
                    if (A.count[j] < A.count[mn]) {
                        mn = j;
                    }
                    if (A.color[j] == B.color[i]) {
                        break;
                    }
                }
                if (j < K) {
                    A.count[j] += B.count[i];
                    continue;
                }
                //printf("%d %d %d\n", mn, A.count[mn], B.color[i]);
                if (A.count[mn] < B.count[i]) {
                    int tmp = A.count[mn];
                    for (j = 0; j < K; ++ j) {
                        A.count[j] -= tmp;
                    }
                    A.count[mn] = B.count[i] - tmp;
                    A.color[mn] = B.color[i];
                    //printf("%d\n", B.count[i]);
                } else {
                    for (j = 0; j < K; ++ j) {
                        A.count[j] -= B.count[i];
                    }
                }
            }
        }
        /*
          printf("nA------");
          for (int i = 0; i < K; ++ i) {
          printf("%d%c", A.color[i], " \n"[i == K - 1]);
          }
          printf("nA------");
          for (int i = 0; i < K; ++ i) {
          printf("%d%c", A.count[i], " \n"[i == K - 1]);
          }
        */
        A.tag = 0;
        return A;
    }
    void pushDown(int l, int r, int rt) {
        int mid = l + r >> 1;
        memset(&T[rt << 1], 0, sizeof T[rt << 1]);
        memset(&T[rt << 1 | 1], 0, sizeof T[rt << 1 | 1]);
        T[rt << 1].tag = T[rt << 1 | 1].tag = T[rt].tag;
        T[rt << 1].color[0] = T[rt << 1 | 1].color[0] = T[rt].tag;
        T[rt].tag = 0;
        T[rt << 1].count[0] = mid - l + 1;
        T[rt << 1 | 1].count[0] = r - mid;
    }
    void build(int l, int r, int rt) {
        if (l == r) {
            T[rt].color[0] = a[l];
            T[rt].count[0] = 1;
            return;
        }
        int mid = l + r >> 1;
        build(lson);
        build(rson);
        T[rt] = pushUp(T[rt << 1], T[rt << 1 | 1]);
    }
    TreeNode query(int cl, int cr, int l, int r, int rt) {
        //printf("%d %d\n", l, r);
        if (cl <= l && r <= cr) {
            return T[rt];
        }
        if (T[rt].tag) {
            //printf("tag------%d %d\n", l, r);
            pushDown(l, r, rt);
        }
        int mid = l + r >> 1;
        if (cr <= mid) {
            return query(cl, cr, lson);
        }
        if (cl >= mid + 1) {
            return query(cl, cr, rson);
        }
        return pushUp(query(cl, cr, lson), query(cl, cr, rson));
    }
    void build(int k) {
        K = k;
        build(1, n, 1);
    }
} t[6];

vector<int> V[N];
int get(int x , int l , int r) {
    return upper_bound(V[x].begin() , V[x].end() , r) -
        lower_bound(V[x].begin() , V[x].end() , l);
}
int main() {
    int q, p, k, l, r, id;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", &a[i]);
        V[a[i]].push_back(i);
    }
    for (int i = 2 ; i <= 5 ; ++ i) {
        t[i].build(i);
    }
    while (q --) {
        scanf("%d%d%d", &l, &r , &k);

        TreeNode ans = t[k].query(l, r, 1, n, 1);
        int res = 1 << 30;
        for (int i = 0; i < k; ++ i) {
            if (get(ans.color[i] , l , r) > (r - l + 1) / k) {
                res = min(res , ans.color[i]);
            }
        }
        if (res == 1 << 30) res = -1;
        printf("%d\n" , res);
    }
    return 0;
}