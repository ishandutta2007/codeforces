#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, q;
long long x, a[100005], ma[100005][20], mi[100005][20];

long long getmax(int l, int r) {
    int Lg = trunc(log2(r - l + 1));
    return max(ma[l][Lg], ma[r - (1<<Lg) + 1][Lg]);
}

long long getmin(int l, int r) {
    int Lg = trunc(log2(r - l + 1));
    return min(mi[l][Lg], mi[r - (1<<Lg) + 1][Lg]);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> x, a[i] -= x;
    for(int i=1; i<=n; ++i) cin >> x, a[i] += x + a[i-1];

    for(int i=1; i<=n; ++i) ma[i][0] = mi[i][0] = a[i];
    for(int j=1; 1<<j<=n; ++j)
    for(int i=1; i + (1<<j) - 1 <=n; ++i) {
        ma[i][j] = max(ma[i][j-1], ma[i + (1<<(j-1))][j-1]);
        mi[i][j] = min(mi[i][j-1], mi[i + (1<<(j-1))][j-1]);
    }

    int l, r;
    while (q--) {
        cin >> l >> r;
        long long maxi = getmax(l, r);
        long long mini = getmin(l, r);
        if (a[r] != a[l-1] || mini < a[l-1]) cout << "-1\n";
        else cout << maxi - a[l-1] << '\n';
    }
}