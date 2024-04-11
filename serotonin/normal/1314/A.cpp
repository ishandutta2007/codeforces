#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

typedef pair <ll,ll> pii;
#define x first
#define y second

pii a[sz];

int main()
{
    ll n;
    cin >> n;
    for(ll i=0; i<n; i++) scanf("%lld", &a[i].x);
    for(ll i=0; i<n; i++) scanf("%lld", &a[i].y);
    sort(a,a+n);

    ll ans=0, v=a[0].x;
    priority_queue <pii> pq;
    for(ll i=0; i<n; i++) {
        if(a[i].x==v) {
            swap(a[i].x, a[i].y);
            pq.push(a[i]);
        }
        else {
            ll d=a[i].x-v;
//            cout << " d " << d << endl;
            while(d-- && !pq.empty()) {
                pii p = pq.top();
                pq.pop();
                ans += p.x * (v-p.y);
                v++;
            }
            v=a[i].x;
            swap(a[i].x, a[i].y);
            pq.push(a[i]);
        }
    }

    while(!pq.empty()) {
        pii p = pq.top();
        pq.pop();
        ans += p.x * (v-p.y);
        v++;
    }

    cout << ans;
}