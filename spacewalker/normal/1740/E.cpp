#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kids;

// {one path, >= 1 path}
pair<int, int> getAns(int v) {
    if (kids[v].size() == 0) return {1, 1};
    else if (kids[v].size() == 1) {
        int op = 0, mp = 0;
        auto [cop, cmp] = getAns(kids[v][0]);
        return {cop + 1, max(cop + 1, cmp)};
    } else {
        int op = 0, mp = 0;
        for (int c : kids[v]) {
            auto [cop, cmp] = getAns(c);
            op = max(op, cop + 1);
            mp += max(cop, cmp);
        }
        return {op, max(op, mp)};
    }
}

int main() {
    int n; scanf("%d", &n);
    kids.resize(n);
    for (int i = 1; i < n; ++i) {
        int p; scanf("%d", &p); kids[p-1].push_back(i);
    }
    printf("%d\n", getAns(0).second);
}