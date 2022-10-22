#include <iostream>
using namespace std;
typedef long long ll;

ll a[500005];
ll s[500005];
ll h[500005];

int main()
{
    ll n, r, k;
    cin >> n >> r >> k;
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
    for(int i = 0; i < n; i++) h[i] = s[min(n, i + 1 + r)] - s[max(0ll, i - r)];

    ll left = -1, right = 1012345678901234567;
    while(right - left > 1){
        ll mid = (right + left) / 2;
        ll d[500005]{0};
        ll t = 0;
        ll c = 0;
        for(int i = 0; i < n; i++){
            if(i >= r * 2 + 1) t -= d[i - (r * 2 + 1)];
            if(h[i] + t < mid){
                d[i] = mid - (h[i] + t);
                t += d[i];
                c += d[i];
                if(c > k) break;
            }
        }
        if(c > k) right = mid;
        else left = mid;
    }
    cout << left << endl;
}