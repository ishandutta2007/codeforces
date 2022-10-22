#include <iostream>
#include <vector>

using namespace std;

const int MAXN = (int) 2e5 + 10;
const int INF = (int) 1e9;
int it[4 * MAXN];
int a[MAXN];
int n;

void update(int u, int L, int R, int ind, int val) {
    if (R - L == 1) {
        it[u] = val;
        return;
    }
    int M = (L + R) / 2;
    if (ind < M) {
        update(2 * u + 1, L, M, ind, val);
    } else {
        update(2 * u + 2, M, R, ind, val);
    }
    it[u] = max(it[2 * u + 1], it[2 * u + 2]);
}

void init(int u, int L, int R) {
    if (R - L == 1) {
        it[u] = a[L];
        return;
    }
    int M = (L + R) / 2;
    init(2 * u + 1, L, M);
    init(2 * u + 2, M, R);
    it[u] = max(it[2 * u + 1], it[2 * u + 2]);
}

int get(int u, int L, int R, int left, int right) {
    if (left >= R || L >= right) {
        return -INF;
    }
    if (left <= L && R <= right) {
        return it[u];
    }
    int M = (L + R) / 2;
    return max(get(2 * u + 1, L, M, left, right), get(2 * u + 2, M, R, left, right));
}

int find(int l, int val) {
    int L = l - 1;
    int R = n;
    while (R - L > 1) {
        int M = (L + R) / 2;
        if (get(0, 0, n, l, M + 1) > val) {
            R = M;
        } else {
            L = M;
        }
    }
    if (R == n) {
        return -1;
    } else {
        return R;
    }
}

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    init(0, 0, n);

    vector<vector<int>> ans;
    while (true) {
        int cur = find(0, 0);
        if (cur == -1) {
            break;
        }
        ans.push_back(vector<int> ());
        while (cur != -1) {
            ans.back().push_back(cur);
            update(0, 0, n, cur, -INF);
            cur = find(cur + 1, a[cur]);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << a[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}