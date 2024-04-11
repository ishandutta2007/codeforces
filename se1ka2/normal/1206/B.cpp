#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int ng = 0, zl = 0;
    ll a[100002];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > 0) ans += a[i] - 1;
        if(a[i] < 0){
            ans += -1 - a[i];
            ng++;
        }
        if(a[i] == 0){
            ans++;
            zl++;
        }
    }
    if(ng % 2 == 1 && zl == 0) ans += 2;
    cout << ans << endl;
}