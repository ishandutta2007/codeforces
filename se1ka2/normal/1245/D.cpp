#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll x[2003], y[2003];
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    ll c[2003];
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    ll k[2003];
    for(int i = 0; i < n; i++) cin >> k[i];
    bool used[2003];
    for(int i = 0; i < n; i++) used[i] = false;
    int connect[2003];
    for(int i = 0; i < n; i++) connect[i] = i;
    while(true){
        ll les = 1000000000000000000;
        int now = -1;
        for(int i = 0; i < n; i++){
            if(used[i]) continue;
            if(now == -1 || c[i] < les){
                now = i;
                les = c[i];
            }
        }
        if(now == -1) break;
        used[now] = true;
        for(int i = 0; i < n; i++){
            if(!used[i]){
                if((abs(x[i] - x[now]) + abs(y[i] - y[now])) * (k[i] + k[now]) < c[i]){
                    c[i] = (abs(x[i] - x[now]) + abs(y[i] - y[now])) * (k[i] + k[now]);
                    connect[i] = now;
                }
            }
        }
    }
    ll ans = 0;
    ll p = 0;
    for(int i = 0; i < n; i++){
        ans += c[i];
        if(connect[i] == i) p++;
    }
    cout << ans << endl;
    cout << p << endl;
    for(int i = 0; i < n; i++) if(connect[i] == i) cout << i + 1 << " ";
    cout << endl;
    cout << n - p << endl;
    for(int i = 0; i < n; i++) if(connect[i] != i) cout << i + 1 << " " << connect[i] + 1 << endl;
}