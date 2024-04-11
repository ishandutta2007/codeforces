#include <bits/stdc++.h>
using namespace std;
#define M 200010

typedef pair <int, int> PII;
typedef long long LL;

int n, K, nx;
int px[M], cx[M], cy[M];

vector <int> v[M];

multiset <PII> setv;

PII p[M];

LL ans[M];

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &K);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cx[i], &cy[i]);
    }
    for (int i = 0; i < n; i++) {
        px[++nx] = cx[i], px[++nx] = cx[i] + K;
    }
    sort(px + 1, px + nx + 1);
    nx = unique(px + 1, px + nx + 1) - px - 1;

    for (int i = 0; i < n; i++) {
        int id = lower_bound(px + 1, px + nx + 1, cx[i]) - px;
        v[id].push_back(cy[i]);
    }

    for (int i = 1; i < nx; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            setv.insert(PII(v[i][j], 1)); setv.insert(PII(v[i][j] + K, -1));
        }
        int id = lower_bound(px + 1, px + nx + 1, px[i] - K) - px;
        if (px[id] == px[i] - K) {
            for (int j = 0; j < v[id].size(); j++) {
                setv.erase(setv.find(PII(v[id][j], 1)));
                setv.erase(setv.find(PII(v[id][j] + K, -1)));
            }
        }
        int d = px[i + 1] - px[i];
        int m = 0;
        for (multiset <PII> :: iterator it = setv.begin(); it != setv.end(); it++) {
            p[m++] = *it;
        }
        /*
        if (px[i] == 8) {
            for (int j = 0; j < m; j++) printf("%d %d\n", p[j].first, p[j].second);
        }
        */
        int cur = 0;
        for (int j = 0; j < m - 1; j++) {
            cur += p[j].second;
            ans[cur] += 1LL * d * (p[j + 1].first - p[j].first);
        }
    }
    for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
    return 0;
}