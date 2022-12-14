#include <bits/stdc++.h>
#define REP(i, l, r) for(int i=l; i<r; i++)
#define FOR(i, l, r) for(int i=l; i<=r; i++)
#define REPD(i, r, l) for(int i=r-1; i>=l; i--)
#define N 100005

using namespace std;
int t, n, cnt, a[2005], f[1000005];
set<int> S;
pair<int,int> Q[2005];

void Process() {
    REP(i, 1, n) {
        S.clear(); cnt = 0;
        FOR(j, 1, n) f[a[j]] = 0;
        FOR(j, 1, n) S.insert(a[j]), f[a[j]]++;
        int sum = a[n] + a[i];
        while (!S.empty()) {
            int v1 = *S.rbegin();
            if (v1*2 < sum) break;
            auto pos = S.lower_bound(sum - v1);
            if (*pos != sum - v1 || *pos == *S.rbegin() && f[*pos] == 1) break;
            if (!--f[v1]) S.erase(v1);
            if (!--f[sum - v1]) S.erase(sum - v1);
            Q[++cnt] = {v1, sum - v1};
            sum = max(v1, sum - v1);
        }
        if (S.empty()) {
            cout << "YES\n" << a[n] + a[i] << '\n';
            FOR(j, 1, cnt) cout << Q[j].first << ' ' << Q[j].second << '\n';
            return;
        }
    }
    cout << "NO\n";
}

void Enter() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n); n *= 2;
        FOR(i, 1, n) scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        Process();
    }
}

int main()
{
    Enter();
}