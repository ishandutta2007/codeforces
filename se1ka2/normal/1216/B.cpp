#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    ll n;
    cin >> n;
    ll a[1002];
    P p[1002];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        p[i] = P(a[i], i);
    }
    sort(p, p + n, greater<P>());
    int ans = n;
    for(int i = 0; i < n; i++) ans += p[i].first * i;
    cout << ans << endl;
    for(int i = 0; i < n; i++) cout << p[i].second + 1 << " ";
    cout << endl;
}