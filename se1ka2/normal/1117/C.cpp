#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll nx = x1, ny = y1;
    ll lx[100002], ly[100002];
    for(int i = 0; i < n; i++){
        lx[i] = nx;
        ly[i] = ny;
        if(s[i] == 'U') ny++;
        if(s[i] == 'D') ny--;
        if(s[i] == 'L') nx--;
        if(s[i] == 'R') nx++;
    }
    ll dx = nx - x1, dy = ny - y1;
    ll ans = 100000000000000000;
    for(int i = 0; i < n; i++){
        ll now = 0, mid = 1048576ll * 4096ll;
        while(mid > 0 && now >= 0){
            if(abs(x2 - (lx[i] + dx * now)) + abs(y2 - (ly[i] + dy * now)) <= i + n * now) now -= mid;
            else now += mid;
            mid /= 2;
        }
        if(now < 0) now = 0;
        if(abs(x2 - (lx[i] + dx * now)) + abs(y2 - (ly[i] + dy * now)) > i + n * now) now++;
        ans = min(ans, i + n * now);
        if(now > 8000000000ll){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}