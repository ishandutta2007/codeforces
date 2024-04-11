#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;

vector<vector<int>> edge;

struct S {
    long long inner_odd_sum, inner_even_sum;
    long long connec_odd_sum;
    long long connec_even_sum;
    long long connec_odd_cnt, connec_even_cnt, inner_odd_cnt;
    S() {
        inner_odd_sum = 0;
        inner_even_sum = 0;
        connec_odd_sum = 0;
        connec_even_sum = 0;
        connec_odd_cnt = 0;
        connec_even_cnt = 0;
        inner_odd_cnt = 0;
    }
};

S compose(S a, S b) {
    S ret;
    ret.connec_odd_sum = a.connec_odd_sum + b.connec_even_sum + b.connec_even_cnt;
    ret.connec_even_sum = a.connec_even_sum + b.connec_odd_sum + b.connec_odd_cnt;
    ret.connec_odd_cnt = a.connec_odd_cnt + b.connec_even_cnt;
    ret.connec_even_cnt = a.connec_even_cnt + b.connec_odd_cnt;
    ret.inner_odd_sum = a.inner_odd_sum + b.inner_odd_sum
            + a.connec_even_sum * b.connec_even_cnt
            + b.connec_even_sum * a.connec_even_cnt
            + a.connec_even_cnt * b.connec_even_cnt
            + a.connec_odd_sum * b.connec_odd_cnt
            + b.connec_odd_sum * a.connec_odd_cnt
            + a.connec_odd_cnt * b.connec_odd_cnt;
    ret.inner_even_sum = a.inner_even_sum + b.inner_even_sum
            + a.connec_even_sum * b.connec_odd_cnt
            + b.connec_odd_sum * a.connec_even_cnt
            + a.connec_even_cnt * b.connec_odd_cnt
            + a.connec_odd_sum * b.connec_even_cnt
            + b.connec_even_sum * a.connec_odd_cnt
            + a.connec_odd_cnt * b.connec_even_cnt;
    ret.inner_odd_cnt = a.inner_odd_cnt + b.inner_odd_cnt
            + a.connec_even_cnt * b.connec_even_cnt
            + a.connec_odd_cnt * b.connec_odd_cnt;

    return ret;
}

S dfs(int p, int par) {
    S ret;
    ret.connec_even_cnt = 1;
    for (int v : edge[p]) {
        if (v == par) continue;
        S s = dfs(v, p);
        ret = compose(ret, s);
    }
    return ret;
}


int main() {
    int n;
    cin >> n;
    edge = vector<vector<int>>(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    S s = dfs(0, -1);
    cout << s.inner_even_sum / 2 + (s.inner_odd_sum + s.inner_odd_cnt) / 2 << "\n";

    return 0;
}