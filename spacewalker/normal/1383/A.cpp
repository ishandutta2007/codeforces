#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n; scanf("%d", &n);
    constexpr int NMAX = 200000;
    static char A[NMAX], B[NMAX];
    scanf("%s", A); scanf("%s", B);
    int ans = 0;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        vector<char> targets;
        for (int i = 0; i < n; ++i) if (A[i] == ch && B[i] != ch) targets.push_back(B[i]);
        sort(begin(targets), end(targets));
        targets.erase(unique(begin(targets), end(targets)), end(targets));
        if (targets.empty()) continue;
        else if (targets[0] < ch) return -1;
        else {
            for (int i = 0; i < n; ++i) if (A[i] == ch && B[i] != ch) A[i] = targets[0];
            ++ans;
        }
    }
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%d\n", solve());
}