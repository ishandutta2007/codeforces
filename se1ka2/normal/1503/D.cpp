#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, bool> PP;

int main()
{
    int n;
    cin >> n;
    PP p[200005];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a < b) p[i] = PP(P(a, b), true);
        else p[i] = PP(P(b, a), false);
        if(a > n && b > n){
            cout << -1 << endl;
            return 0;
        }
    }
    sort(p, p + n);
    int u = n * 2, d = n * 2;
    bool c[400005]{0};
    int f[200005];
    int ans = 0;
    int l = 0;
    for(int i = 0; i < n; i++){
        int x = p[i].first.second;
        c[x] = true;
        if(x == u){
            f[i] = 2;
            while(c[u]) u--;
            if(d > u) d = u;
        }
        else if(x <= d){
            f[i] = 1;
            d = x - 1;
        }
        else{
            cout << -1 << endl;
            return 0;
        }
        if(u == d){
            int s = 0, t = 0;
            for(int j = l; j <= i; j++){
                bool g = p[j].second;
                if((g && f[j] == 2) || (!g && f[j] == 1)) s++;
                if((g && f[j] == 1) || (!g && f[j] == 2)) t++;
            }
            ans += min(s, t);
            l = i + 1;
        }
    }
    cout << ans << endl;
}