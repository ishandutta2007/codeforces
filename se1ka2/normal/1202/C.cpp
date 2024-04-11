#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        string s;
        cin >> s;
        int n = s.size();
        ll x = 0, y = 0;
        ll u = 0, d = 0, l = 0, r = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'W') x++;
            if(s[i] == 'S') x--;
            if(s[i] == 'A') y++;
            if(s[i] == 'D') y--;
            u = max(u, x);
            d = min(d, x);
            r = max(r, y);
            l = min(l, y);
        }
        int lx = 0, ly = 0;
        int kx = 0, ky = 0;
        x = 0, y = 0;
        for(int i = 0; i <= n; i++){
            if(x == u && lx != 1){
                lx = 1;
                kx++;
            }
            if(x == d && lx != -1){
                lx = -1;
                kx++;
            }
            if(y == r && ly != 1){
                ly = 1;
                ky++;
            }
            if(y == l && ly != -1){
                ly = -1;
                ky++;
            }
            if(i == n) break;
            if(s[i] == 'W') x++;
            if(s[i] == 'S') x--;
            if(s[i] == 'A') y++;
            if(s[i] == 'D') y--;
        }
        ll ans = (u - d + 1) * (r - l + 1);
        if(kx == 2 && u - d >= 2) ans = min(ans, (u - d) * (r - l + 1));
        if(ky == 2 && r - l >= 2) ans = min(ans, (u - d + 1) * (r - l));
        cout << ans << endl;
    }
}