# include <iostream>  
# include <algorithm>   
using namespace std;  
typedef long long int ll;  
int main(){  
    ll a, b, c;  
    cin >> a >> b >> c;  
    ll m = max(a, max(b, c));  
    ll ans = 0;  
    if (a < m) ans += m - 1 - a;  
    if (b < m) ans += m - 1 - b;  
    if (c < m) ans += m - 1 - c;  
    cout << ans << endl;  
    return 0;  
}