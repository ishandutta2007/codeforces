#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
 
int main()
{
    ll n, z;
    cin >> n >> z;
    ll x[200005];
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);
    int ans = 0;
    int i = 0, j = n / 2;
    while(i < n / 2 && j < n){
        while(j < n && x[i] + z > x[j]) j++;
        if(j == n) break;
        ans++;
        i++;
        j++;
    }
    cout << ans << endl;
}