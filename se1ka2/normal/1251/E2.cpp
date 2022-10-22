#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll p[200004];
ll m[200004];
P pa[200004];
ll b[200004];

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        fill(b, b + n + 1, 0);
        for(int i = 0; i < n; i++){
            cin >> m[i] >> p[i];
            pa[i] = P(m[i], p[i]);
        }
        sort(pa, pa + n);
        b[pa[0].first] = pa[0].first;
        for(int i = 1; i < n; i++){
            if(pa[i].first != pa[i - 1].first) b[pa[i].first] = max((ll)0, pa[i].first - i);
        }
        priority_queue<ll, vector<ll>, greater<ll>> que;
        ll h = 0;
        ll ans = 0;
        for(int i = n - 1; i >= 0; i--){
            que.push(pa[i].second);
            if(i == 0 || pa[i].first != pa[i - 1].first){
                for(int j = 0; j < b[pa[i].first] - h; j++){
                    ans += que.top();
                    que.pop();
                }
                h += max((ll)0, b[pa[i].first] - h);
            }
        }
        cout << ans << endl;
    }
}