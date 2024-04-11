#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        priority_queue<P> que;
        ll a[100005], b[100005];
        for(int i = 0; i < m; i++){
            cin >> a[i] >> b[i];
            que.push(P(a[i], -1));
            que.push(P(b[i], i));
        }
        ll c = 0;
        ll s = 0;
        ll ans = 0;
        while(c < n && !que.empty()){
            P p = que.top();
            que.pop();
            if(p.second == -1){
                s += p.first;
                c++;
            }
            else{
                if(a[p.second] >= p.first){
                    ans = max(ans, s + (n - c) * p.first);
                }
                else{
                    ans = max(ans, s + a[p.second] + (n - c - 1) * p.first);
                }
            }
        }
        ans = max(ans, s);
        cout << ans << endl;
    }
}