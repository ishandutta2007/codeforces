#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main()
{
    ll n, w;
    cin >> n >> w;
    ll a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll t[200005];
    for(int i = 0; i < n; i++) cin >> t[i];
    ll s = 0;
    ll l = 0;
    for(int i = 0; i < n; i++){
        s += a[i] * t[i];
        l += a[i];
    }
    if(s == w * l){
        cout << l << endl;
        return 0;
    }
    P p[200005];
    for(int i = 0; i < n; i++) p[i] = P(t[i], a[i]);
    if(s < w * l){
        sort(p, p + n, greater<P>());
        s = 0;
        l = 0;
        for(int i = 0; i < n; i++){
            if(s + p[i].first * p[i].second < w * (l + p[i].second)){
                double x = (w * l - s) * 1.0 / (p[i].first - w);
                cout << fixed << setprecision(15) << x + l << endl;
                return 0;
            }
            s += p[i].first * p[i].second;
            l += p[i].second;
        }
    }
    else{
        sort(p, p + n);
        s = 0;
        l = 0;
        for(int i = 0; i < n; i++){
            if(s + p[i].first * p[i].second > w * (l + p[i].second)){
                double x = (w * l - s) * 1.0 / (p[i].first - w);
                cout << fixed << setprecision(15) << x + l << endl;
                return 0;
            }
            s += p[i].first * p[i].second;
            l += p[i].second;
        }
    }
}