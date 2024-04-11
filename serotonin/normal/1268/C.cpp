#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
const ll sz=2e5+5;

#define ordered_set tree <ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set st;

ll a[sz], where[sz];
ll bit[sz];

void add(ll x, ll what, ll n)
{
    while(x<=n) {
        bit[x]+=what;
        x += x & (-x);
    }
}

ll quer(ll x)
{
    ll now=0;
    while(x) {
        now+=bit[x];
        x -= x & (-x);
    }
    return now;
}

ll fnc(ll x)
{
    return x*(x+1)/2;
}

int main()
{
    ll n;
    cin >> n;
    for(ll i=1; i<=n; i++) scanf("%lld", &a[i]), where[a[i]]=i;

    ll nijera=0, tot=0;
    for(ll i=1; i<=n; i++) {
        ll x=st.order_of_key(where[i]);
        nijera += (i-1)-x;
        st.insert(where[i]);
        add(where[i], where[i], n);
        tot+=where[i];

        ll hole=*st.find_by_order(i>>1);
        ll ans=nijera;

        ll smolsum=quer(hole-1), smolcnt=st.order_of_key(hole);
        ans += (smolcnt*hole - smolsum) - fnc(smolcnt);

        ll bigsum=tot-quer(hole), bigcnt=i-st.order_of_key(hole+1);
        ans += (bigsum - bigcnt*hole) - fnc(bigcnt);

        printf("%lld ", ans);
    }
}