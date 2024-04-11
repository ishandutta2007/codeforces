#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll k, x;
    cin >> n >> k >> x;
    ll a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for(int i = 0; i < n - 1; i++){
        que.push(max(0ll, a[i + 1] - a[i] - 1) / x);
    }
    int ans = n;
    while(que.size()){
        ll d = que.top();
        que.pop();
        k -= d;
        if(k >= 0) ans--;
        else break;
    }
    cout << ans << endl;
}