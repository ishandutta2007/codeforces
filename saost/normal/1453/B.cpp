#include <iostream>
using namespace std;
int t, n, a[200005];
long long tc, tr, nt, now_tc, now_tr, now_nt;
int main()
{
    //freopen("main.inp","r",stdin);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &a[i]);
        tc = tr = nt = 0; a[n+1] = a[n-1];
        for(int i=n-1; i; i--) {
            now_tc = abs(a[i] - a[i+1]) + tc;
            now_tr = min(tr + abs(a[i] - a[i+1]), nt + abs(a[i] - a[i+2]));
            now_nt = tc;
            tc = now_tc; tr = now_tr; nt = now_nt;
        }
        cout << min(tc, min(tr, nt)) << '\n';
    }
}