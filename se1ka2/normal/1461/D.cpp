#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

ll dfs(int l, int r, ll *a, set<ll> &st, int n){
    int m = upper_bound(a, a + n, (a[l] + a[r - 1]) / 2) - a;
    if(m == r){
        st.insert(a[l] * (r - l));
        return a[l] * (r - l);
    }
    ll res = dfs(l, m, a, st, n) + dfs(m, r, a, st, n);
    st.insert(res);
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, q;
        scanf("%d %d", &n, &q);
        ll a[100005];
        for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
        sort(a, a + n);
        set<ll> st;
        dfs(0, n, a, st, n);
        while(q--){
            int s;
            scanf("%d", &s);
            if(st.find(s) != st.end()) printf("YES\n");
            else printf("NO\n");
        }
    }
}