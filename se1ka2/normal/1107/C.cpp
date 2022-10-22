#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    ll a[200005];
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    string s;
    cin >> s;
    s += '.';
    ll ans = 0;
    int l = 0;
    for(int i = 0; i < n; i++){
        priority_queue<ll> que;
        while(s[i] == s[i + 1]){
            que.push(a[i]);
            i++;
            l++;
        }
        que.push(a[i]);
        l++;
        for(int j = 0; j < min(l, k); j++){
            ans += que.top();
            que.pop();
        }
        l = 0;
    }
    cout << ans << endl;
}