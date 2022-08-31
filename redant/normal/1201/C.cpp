// https://codeforces.com/contest/1201/problem/C

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 200005;
int n, m;
LL k;
LL a[SZ];

int main() {
    setIO();
    cin>>n>>k;
    for (int i = 0; i < n; i++) cin>>a[i];
    sort(a, a+n);
    m = n/2;
    LL sum = a[m];
    int last = m;
    while (last + 1 < n && ((last-m+1) * a[last+1] - sum) <= k) {
        ++last;
        sum += a[last];
    }
    // cout<<"last = "<<last<<endl;
    k -= ((last-m+1) * a[last] - sum);
    LL ans = a[last] + (k / (last + 1 - m));
    cout<<ans<<endl;
    return 0;
}