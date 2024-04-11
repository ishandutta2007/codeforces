#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll l[200005], r[200005];
ll up[200005];

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll n, s;
        scanf("%lld %lld", &n, &s);
        for(int i = 0; i < n; i++){
            scanf("%lld %lld", &l[i], &r[i]);
        }
        ll now = 1048576 * 1024;
        ll mid = now / 2;
        while(mid > 0){
            ll u = 0;
            ll sum = 0;
            for(int i = 0; i < n; i++){
                if(r[i] < now) sum += l[i];
                else{
                    up[u] = l[i];
                    u++;
                }
            }
            if(u <= n / 2){
                now -= mid;
                mid /= 2;
                continue;
            }
            sort(up, up + u);
            for(int i = 0; i < u - n / 2 - 1; i++) sum += up[i];
            for(int i = u - n / 2 - 1; i < u; i++) sum += max(now, up[i]);
            if(sum <= s) now += mid;
            else now -= mid;
            mid /= 2;
        }
        ll u = 0;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            if(r[i] < now) sum += l[i];
            else{
                up[u] = l[i];
                u++;
            }
        }
        if(u <= n / 2){
            now--;
            cout << now << endl;
            continue;
        }
        sort(up, up + u);
        for(int i = 0; i < u - n / 2 - 1; i++) sum += up[i];
        for(int i = u - n / 2 - 1; i < u; i++) sum += max(now, up[i]);
        if(sum > s) now--;
        cout << now << endl;
    }
}