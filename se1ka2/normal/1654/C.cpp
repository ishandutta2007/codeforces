#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll s = 0;
        ll a[200005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
        }
        sort(a, a + n, greater<ll>());
        priority_queue<ll> que;
        que.push(s);
        int i = 0;
        while(que.size()){
            ll x = que.top();
            que.pop();
            if(x < a[i]) break;
            if(x == a[i]) i++;
            else{
                que.push(x / 2);
                que.push((x + 1) / 2);
            }
        }
        if(que.size()) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}