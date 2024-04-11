#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 200500;

int a[N], nxt[N];

vector<int> vec[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) vec[i].clear();
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        vec[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (vec[i].size() > 1) {
            int st = vec[i][0], en = vec[i].back();
            if (en > st + 1) nxt[st] = en;
        }
    }
    int ans = 0;
    for (int i = 1, j = 1; i <= n; ) {
        for (; i <= n; i++) if (nxt[i]) break;
        int p = nxt[i], pp = 0;
        j = i + 1;
        while (1) {
            for (; j <= n && j < p; j++) {
                ans++;
                pp = max(pp, nxt[j]);
            }
            if (pp <= p) break;
            ans--;
            p = pp;
        }
        i = j + 1;
    }
    printf("%d\n", ans);

    return 0;
}