#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    ll a[200002];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll s[200002] {0};
    ll ans = 0;
    int d = 0;
    bool f = true;
    while(f){
        for(int i = 0; i < m; i++){
            if(d * m + i == n){
                f = false;
                break;
            }
            s[i] += a[d * m + i];
            ans += s[i];
            cout << ans << " ";
        }
        if(!f) break;
        d++;
    }
    cout << endl;
}