#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[300000];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(a[n - 1] == -1){
        cout << 0 << endl;
        return 0;
    }
    ll ans = a[n - 1];
    int m = n / 2;
    int i = n - 2;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    while(true){
        bool f = false;
        for(int j = i; j > i - m; j--){
            que.push(a[j]);
            if(a[j] == -1) f = true;
        }
        if(f) break;
        ans += que.top();
        que.pop();
        i -= m;
        m /= 2;
    }
    cout << ans << endl;
}