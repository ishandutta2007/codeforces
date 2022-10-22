#include <iostream>
using namespace std;
typedef long long ll;

const int INF = 1000000000;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int w, h;
        cin >> w >> h;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int u, v;
        cin >> u >> v;
        int ans = INF;
        if((x2 - x1) + u <= w) ans = min(ans, max(0, u - max(x1, w - x2)));
        if((y2 - y1) + v <= h) ans = min(ans, max(0, v - max(y1, h - y2)));
        if(ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }
}