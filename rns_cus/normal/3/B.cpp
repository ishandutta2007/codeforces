#include <bits/stdc++.h>
using namespace std;

#define N 100100
typedef pair <int, int> pii;
vector <pii> v[2];
vector <int> ans;
int rlt, n, m;

void push(int k) {
    rlt += v[k].back().first;
    ans.push_back(v[k].back().second);
    m -= k + 1; v[k].pop_back();
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        int t, p;
        scanf("%d %d", &t, &p);
        v[t-1].emplace_back(p, i);
    }
    for (int i = 0; i < 2; i ++) sort(v[i].begin(), v[i].end());
    while (m > 0) {
        if (v[0].empty()) {
            if (v[1].empty()) break;
            if (m > 1) push(1);
            else break;
        }
        else if (v[1].empty()) push(0);
        else {
            if (m == 1) push(0);
            else if (v[0].size() == 1) {
                if (v[0].back().first > v[1].back().first) push(0);
                else push(1);
            }
            else {
                int sz = v[0].size();
                if (v[0][sz-1].first + v[0][sz-2].first > v[1].back().first) push(0);
                else push(1);
            }
        }
    }
    printf("%d\n", rlt);
    sort(ans.begin(), ans.end());
    for (auto x : ans) printf("%d ", x); puts("");
    return 0;
}