#include <bits/stdc++.h>
using namespace std;

vector < vector <int> > ans, tmp;

void solve(int n) {
    if (n == 1) {
        ans.push_back(vector <int> (1));
        return;
    }
    solve(n - 1);
    tmp = ans;
    ans.clear();
    int sz = tmp.size();
    for (int i = 0; i < sz; i ++) {
        int m = 0;
        for (int j = 0; j < n - 1; j ++) m = max(m, tmp[i][j]); m ++;
        if (i & 1) {
            vector <int> v = tmp[i];
            v.push_back(1); ans.push_back(v);
            for (int j = m; ~j; j --) if (j != 1) v[n-1] = j, ans.push_back(v);
        }
        else {
            vector <int> v = tmp[i];
            v.push_back(0); ans.push_back(v);
            for (int j = m; j; j --) v[n-1] = j, ans.push_back(v);
        }
    }
}

vector <int> v[11];

int main() {
//    freopen("I.in", "r", stdin);
    int n;
    scanf("%d", &n);
    solve(n);
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i ++) {
        for (int j = 0; j < n; j ++) v[j].clear();
        for (int j = 0; j < n; j ++) v[ans[i][j]].push_back(j + 1);
        for (int j = 0; ; j ++) {
            if (v[j].empty()) break;
            if (j) putchar(',');
            int p = v[j].size();
            for (int k = 0; k < p; k ++) {
                if (k) putchar(',');
                else putchar('{');
                printf("%d", v[j][k]);
            }
            putchar('}');
        }
        puts("");
    }

    return 0;
}