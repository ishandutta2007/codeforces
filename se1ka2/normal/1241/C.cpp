#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll p[200005];

ll gcd(ll n, ll m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

ll lcm(ll n, ll m){
    return (n / gcd(n, m)) * m;
}

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        ll n;
        cin >> n;
        for(int i = 0; i < n; i++){
            scanf("%lld", &p[i]);
            p[i] /= 100;
        }
        sort(p, p + n, greater<ll>());
        ll x, a;
        cin >> x >> a;
        ll y, b;
        cin >> y >> b;
        ll k;
        cin >> k;
        ll now = 131072;
        ll mid = now / 2;
        while(mid > 0){
            if(now > n){
                now -= mid;
                mid /= 2;
                continue;
            }
            ll nab = now / lcm(a, b);
            ll na = now / a - nab;
            ll nb = now / b - nab;
            ll sum = 0;
            for(int i = 0; i < nab; i++) sum += p[i] * (x + y);
            if(x > y){
                for(int i = nab; i < nab + na; i++) sum += p[i] * (x);
                for(int i = nab + na; i < nab + na + nb; i++) sum += p[i] * (y);
            }
            else{
                for(int i = nab; i < nab + nb; i++) sum += p[i] * (y);
                for(int i = nab + nb; i < nab + na + nb; i++) sum += p[i] * (x);
            }
            if(sum >= k) now -= mid;
            else now += mid;
            mid /= 2;
        }
        if(now > n){
            cout << -1 << endl;
            continue;
        }
        ll nab = now / lcm(a, b);
        ll na = now / a - nab;
        ll nb = now / b - nab;
        ll sum = 0;
        for(int i = 0; i < nab; i++) sum += p[i] * (x + y);
        if(x > y){
            for(int i = nab; i < nab + na; i++) sum += p[i] * (x);
            for(int i = nab + na; i < nab + na + nb; i++) sum += p[i] * (y);
        }
        else{
            for(int i = nab; i < nab + nb; i++) sum += p[i] * (y);
            for(int i = nab + nb; i < nab + na + nb; i++) sum += p[i] * (x);
        }
        if(sum < k) now++;
        if(now > n) cout << -1 << endl;
        else cout << now << endl;
    }
}