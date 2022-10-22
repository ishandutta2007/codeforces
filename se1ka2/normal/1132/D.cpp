#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll a[200003], b[200003];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll now = 0;
    ll mid = 1048576ll * 1048576ll * 2ll;
    while(mid > 0 && now >= 0){
        priority_queue<P, vector<P>, greater<P>> que;
        ll c[200003];
        for(int i = 0; i < n; i++) c[i] = a[i];
        for(int i = 0; i < n; i++){
            if(a[i] / b[i] < k) que.push(P(a[i] / b[i], i));
        }
        int i = 0;
        while(true){
            if(que.empty() || i >= k){
                now -= mid;
                mid /= 2;
                break;
            }
            P p = que.top();
            que.pop();
            if(p.first < i){
                now += mid;
                mid /= 2;
                break;
            }
            c[p.second] += now;
            if(c[p.second] / b[p.second] < k) que.push(P(c[p.second] / b[p.second], p.second));
            i++;
        }
    }
    if(now < 0){
        cout << 0 << endl;
        return 0;
    }
    priority_queue<P, vector<P>, greater<P>> que;
    ll c[200003];
    for(int i = 0; i < n; i++) c[i] = a[i];
    for(int i = 0; i < n; i++){
        if(a[i] / b[i] < k) que.push(P(a[i] / b[i], i));
    }
    int i = 0;
    while(true){
        if(que.empty() || i >= k){
            break;
        }
        P p = que.top();
        que.pop();
        if(p.first < i){
            now++;
            break;
        }
        c[p.second] += now;
        if(c[p.second] / b[p.second] < k) que.push(P(c[p.second] / b[p.second], p.second));
        i++;
    }
    if(now > 4000000000000ll) cout << -1 << endl;
    else cout << now << endl;
}