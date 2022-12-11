#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k; ll A, B;
vector<int> avengers;

ll solve(int ri, int rj, int ai, int aj) {
    auto cont = [&] () {
        if (ai == aj) return A;
        if (ri + 1 == rj) return B * (aj - ai) * (rj - ri);
        int rmid = (ri + rj) / 2;
        int amid = ai;
        while (amid < aj && avengers[amid] < rmid) ++amid;
        return min(B * (aj - ai) * (rj - ri),
                solve(ri, rmid, ai, amid) + solve(rmid, rj, amid, aj));
    };
    ll ans = cont();
//    printf("%d %d %d %d ans %lld\n", ri, rj, ai, aj, ans);
    return ans;
}

int main() {
    scanf("%d %d %lld %lld", &n, &k, &A, &B);
    avengers.assign(k, 0);
    for (int i = 0; i < k; ++i) scanf("%d", &avengers[i]);
    for (int &v : avengers) --v;
    sort(begin(avengers), end(avengers));
    printf("%lld\n", solve(0, (1 << n), 0, k));
}