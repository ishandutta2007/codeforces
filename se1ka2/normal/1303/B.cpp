#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll n, g, b;
        cin >> n >> g >> b;
        ll now = 1048576ll * 1048576ll * 1048576ll;
        ll mid = now / 2;
        while(mid){
            ll r = now / (g + b) * g + min(g, now % (g + b));
            if(r >= (n + 1) / 2 && now >= n) now -= mid;
            else now += mid;
            mid /= 2;
        }
        ll r = now / (g + b) * g + min(g, now % (g + b));
        if(r < (n + 1) / 2 || now < n) now++;
        cout << now << endl;
    }
}