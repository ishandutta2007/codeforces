#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000009;

int main()
{
    int n;
    cin >> n;
    ll c[1002];
    for(int i = 0; i < n; i++) cin >> c[i];
    ll ans = 0;
    for(int i = 0; i < n; i += 2){
        ll h = 0, l = c[i] - 1;
        for(int j = i; j < n; j++){
            if((i + j) % 2){
                h -= c[j];
                if(0 <= h && h <= l) ans += l - h + 1;
                else if(h <= l){
                    ans += l + 1;
                    break;
                }
                l = min(l, h);
            }
            else h += c[j];
            l = min(l, h);
        }
    }
    cout << ans << endl;
}