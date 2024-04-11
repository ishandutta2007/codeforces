#include <iostream>
#include <vector>

using namespace std;

int n;
const int MAXN = (int) 1e5 + 10;
char s[MAXN];
vector<int> p;
int nxt[MAXN], prv[MAXN];

bool meme(int fr, int l, int r, int t) {
    l = nxt[l];
    r = prv[r];
    if (r < l) return true;
    return min(abs(fr - r) + abs(r - l), abs(fr - l) + abs(r - l)) <= t;
}

bool check(int t) {
    vector<int> dp(p.size() + 1);
    for (int i = 0; i < p.size(); i++) {
        int pp = dp[i];
        int L = pp - 1;
        int R = n;
        while (R - L > 1) {
            int M = (L + R) / 2;
            if (meme(p[i], pp, M, t)) {
                L = M;
            } else {
                R = M;
            }
        }
        dp[i + 1] = R;
    }
    return dp[p.size()] >= n;
}

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif

    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            prv[i] = i;
        } else {
            if (i == 0) {
                prv[i] = -1;
            } else {
                prv[i] = prv[i - 1];
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '*') {
            nxt[i] = i;
        } else {
            if (i == n - 1) {
                nxt[i] = n;
            } else {
                nxt[i] = nxt[i + 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            p.push_back(i);
        }
    }

    int L = 0;
    int R = 2 * n;
    while (R - L > 1) {
        int M = (L + R) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }

    cout << R << endl;

    return 0;
}