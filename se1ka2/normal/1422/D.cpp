#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main()
{
    ll n;
    int m;
    cin >> n >> m;
    ll sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    ll x[100005], y[100005];
    P px[100005], py[100005];
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
        px[i] = P(x[i], i);
        py[i] = P(y[i], i);
    }
    x[m] = sx, y[m] = sy;
    px[m] = P(x[m], m);
    py[m] = P(y[m], m);
    sort(px, px + m + 1);
    sort(py, py + m + 1);
    ll d[100005];
    for(int i = 0; i < m; i++) d[i] = -1;
    d[m] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, m));
    while(que.size()){
        P p = que.top();
        que.pop();
        int i = p.second;
        if(d[i] < p.first) continue;
        int lx = upper_bound(px, px + m + 1, P(x[i], i)) - px;
        if(lx != m + 1){
            int j = px[lx].second;
            if(d[j] == -1 || d[j] > d[i] + abs(x[i] - x[j])){
                d[j] = d[i] + abs(x[i] - x[j]);
                que.push(P(d[j], j));
            }
        }
        lx -= 2;
        if(lx >= 0){
            int j = px[lx].second;
            if(d[j] == -1 || d[j] > d[i] + abs(x[i] - x[j])){
                d[j] = d[i] + abs(x[i] - x[j]);
                que.push(P(d[j], j));
            }
        }
        int ly = upper_bound(py, py + m + 1, P(y[i], i)) - py;
        if(ly != m + 1){
            int j = py[ly].second;
            if(d[j] == -1 || d[j] > d[i] + abs(y[i] - y[j])){
                d[j] = d[i] + abs(y[i] - y[j]);
                que.push(P(d[j], j));
            }
        }
        ly -= 2;
        if(ly >= 0){
            int j = py[ly].second;
            if(d[j] == -1 || d[j] > d[i] + abs(y[i] - y[j])){
                d[j] = d[i] + abs(y[i] - y[j]);
                que.push(P(d[j], j));
            }
        }
    }
    ll ans = n * 2;
    for(int i = 0; i <= m; i++){
        ans = min(ans, d[i] + abs(x[i] - fx) + abs(y[i] - fy));
    }
    cout << ans << endl;
}