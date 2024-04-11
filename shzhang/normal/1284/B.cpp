#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long

int n;
int l[100005];
bool asc[100005];
vector<int> seq[100005];
int maxcnt[1000005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", l + i);
        for (int j = 1; j <= l[i]; j++) {
            int a;
            scanf("%d", &a);
            seq[i].push_back(a);
            if (j > 1 && seq[i][j-1] > seq[i][j-2]) asc[i] = true;
        }
    }
    ll base = 0;
    int asccnt = 0;
    for (int i = 1; i <= n; i++) if (asc[i]) asccnt++;
    for (int i = 1; i <= n; i++) {
        if (asc[i]) {
            base += (ll)n;
        } else {
            base += (ll)asccnt;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (asc[i]) continue;
        maxcnt[seq[i][0]]++;
    }
    for (int i = 1000002; i >= 0; i--) {
        maxcnt[i] += maxcnt[i+1];
    }
    for (int i = 1; i <= n; i++) {
        if (asc[i]) continue;
        int minval = seq[i][seq[i].size() - 1];
        base += (ll)maxcnt[minval + 1];
    }
    printf("%lld", base);
    return 0;
}