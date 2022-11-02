#include <bits/stdc++.h>
using namespace std;

#define N 100100

typedef long long ll;
typedef pair <int, int> pii;

int n, p, t[N];
ll ans[N];
vector <pii> vec;
set <int> rem;
queue <int> q; set <int> S;

void add(int x) {
    q.push(x);
    S.insert(x);
}

void del() {
    int x = q.front();
    S.erase(x), q.pop();
}

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i ++) scanf("%d", &t[i]), vec.emplace_back(t[i], i);
    sort(vec.begin(), vec.end());
    ll cur = 0;
    int k = 0;
    while (k < n || !q.empty()) {
        if (k < n && q.empty()) cur = max(cur, (ll)vec[k].first), add(vec[k].second), k ++;
        ll up = cur + p;
        int r = q.front(); ans[r] = up; r = *S.begin();
        while (cur < up) {
            while (k < n && vec[k].first == cur) rem.insert(vec[k].second), k ++;
            cur ++;
            if (rem.empty() || *rem.begin() > r) {
                cur = up;
                if (k < n) cur = min(up, (ll)vec[k].first);
            }
            else {
                auto it = rem.begin();
                add(r = *it), rem.erase(it);
            }
        }
        del(); r = q.empty() ? 2e9 : *S.begin();
        while (k < n && vec[k].first == cur) rem.insert(vec[k].second), k ++;
        if (!rem.empty()) {
            auto it = rem.begin();
            if (*it < r) add(r = *it), rem.erase(it);
        }
    }
    for (int i = 1; i <= n; i ++) printf("%I64d ", ans[i]);

    return 0;
}