#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 10000000000000;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll z[4][2];
        for(int i = 0; i < 4; i++) cin >> z[i][0] >> z[i][1];
        ll ans = INF;
        int p[4];
        for(int i = 0; i < 4; i++) p[i] = i;
        do{
            for(int c = 0; c < 2; c++){
                for(int i = 0; i < 4; i++) swap(z[i][0], z[i][1]);
                int u = p[0], v = p[1], w = p[2], x = p[3];
                ll s = abs(z[u][0] - z[w][0]) + abs(z[v][0] - z[x][0]);
                ll d = abs(z[u][0] - z[v][0]);
                if(z[u][1] > z[w][1]) swap(u, w);
                if(z[v][1] > z[x][1]) swap(v, x);
                s += min({abs(z[u][1] - z[v][1]) + abs(z[u][1] + d - z[w][1]) + abs(z[u][1] + d - z[x][1]),
                          abs(z[v][1] - z[u][1]) + abs(z[v][1] + d - z[x][1]) + abs(z[v][1] + d - z[w][1]),
                          abs(z[w][1] - z[x][1]) + abs(z[w][1] - d - z[u][1]) + abs(z[w][1] - d - z[v][1]),
                          abs(z[x][1] - z[w][1]) + abs(z[x][1] - d - z[v][1]) + abs(z[x][1] - d - z[u][1])});
                ans = min(s, ans);
            }
        }while(next_permutation(p, p + 4));
        cout << ans << endl;
    }
}