#include <bits/stdc++.h>
#define REP(i, l, r) for(int i=l; i<r; i++)
#define FOR(i, l, r) for(int i=l; i<=r; i++)
#define REPD(i, r, l) for(int i=r-1; i>=l; i--)
#define N 100005

using namespace std;
int t, d, cnt, f[30005], prime[30005];

void eratos() {
    int NN = 30000;
    FOR(i, 2, NN) {
        if (!f[i]) prime[++cnt] = f[i] = i;
        int j = 1;
        while (j <= cnt && prime[j]*i <= NN && prime[j] <= f[i]) {
            f[prime[j]*i] = prime[j];
            j++;
        }
    }
}

void Process() {
    int x1 = upper_bound(prime+1, prime+cnt, d) - prime;
    int x2 = lower_bound(prime+1, prime+cnt, prime[x1] + d) - prime;
    x1 = prime[x1]; x2 = prime[x2];
    cout << min((long long) x1*x1*x1, (long long) x1*x2) << '\n';
}

void Enter() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &d);
        Process();
    }
}

int main()
{
    eratos();
    Enter();
}