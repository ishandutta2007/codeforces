#include <bits/stdc++.h>
using namespace std;
set <int> s;
int n, x, m;
vector <int> ans;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s.insert(x);
    }
    for (int i = 1; true; i++) {
        if (i > m)
            break;
        if (s.find(i) != s.end())
            continue;
        m -= i;
        ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%d ", ans[i]);
}