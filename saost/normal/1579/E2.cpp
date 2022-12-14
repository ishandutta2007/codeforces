#include <bits/stdc++.h>
using namespace std;
int t, n, x, cnt, a[200005], *b[200005], bit[200005], same[200005];
long long res;

int query(int x) {
    int val = 0;
    for(--x; x; x-=x&-x) val += bit[x];
    return val;
}

void update(int x) {
    for(; x<=cnt; x+=x&-x) ++bit[x];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cnt = res = 0;
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i], b[i] = &a[i];
        sort(b+1, b+n+1, [] (int *x, int *y) { return *x < *y; });
        for(int i=1, old; i<=n; ++i) {
            if (cnt==0 || old != *b[i]) ++cnt, old = *b[i];
            *b[i] = cnt;
        }
        for(int i=1; i<=cnt; ++i) bit[i] = same[i] = 0;
        for(int i=1; i<=n; ++i) {
            int choice_L = query(a[i]);
            int choice_R = i - choice_L - same[a[i]] - 1;
            res += min(choice_L, choice_R);
            update(a[i]);
            ++same[a[i]];
        }
        cout << res << '\n';
    }
}