#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    int n;
    cin >> n;
    P p[400005];
    for(int i = 0; i < n; i++){
        ll l, r;
        cin >> l >> r;
        r++;
        p[i * 2] = P(l, 1);
        p[i * 2 + 1] = P(r, 0);
    }
    sort(p, p + n * 2);
    int h = 0;
    ll ans[200005]{0};
    for(int i = 0; i < n * 2; i++){
        if(h > 0) ans[h] += p[i].first - p[i - 1].first;
        if(p[i].second == 0) h--;
        else h++;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}