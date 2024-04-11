#include <bits/stdc++.h>

const int maxn = 105;

int n, k, m, a, c[maxn], last[maxn], r[maxn];

bool better(int ca, int lasta, int cb, int lastb) {
    if (ca != cb) return ca > cb;
    else return lasta < lastb;
}

int main() {
    scanf("%d%d%d%d", &n, &k, &m, &a);
    for (int i = 0; i < a; i++) {
        int v;
        scanf("%d", &v);
        v--;
        c[v]++;
        last[v] = i;
    }
    for (int i = 0; i < n; i++) {
        int defbeat = 0;
        int fakec = c[i] + m-a;
        int fakelast = (m == a ? last[i] : m-1);
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (better(c[j], last[j], fakec, fakelast)) {
                defbeat++;
            }
        }
        if (defbeat >= k || (c[i] == 0 && m == a)) {
            r[i] = 3; // definitely lose. feelsbadman
            continue;
        }

        int alreadybeat = 0;
        std::vector<int> potential;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (better(c[j], last[j], c[i], last[i])) {
                alreadybeat++;
            } else {
                potential.push_back(c[j]);
            }
        }
        std::sort(potential.begin(), potential.end());
        int left = m-a;
        while (left && !potential.empty()) {
            potential.back()++;
            if (potential.back() > c[i]) {
                alreadybeat++;
                potential.pop_back();
            }
            left--;
        }
        if (alreadybeat >= k || c[i] == 0) {
            r[i] = 2; // could have a seat
        } else {
            r[i] = 1; // defs has a seat
        }
    }

    for (int i = 0; i < n; i++) printf("%d%c", r[i], " \n"[i == n-1]);
}