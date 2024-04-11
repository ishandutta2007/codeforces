#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll a[200003];
    ll b[200003] {0};
    ll s[2];
    int k = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0){
            k = 1 - k;
        }
        b[i] = k;
        s[k]++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i == 0) ans += s[0];
        else ans += s[b[i - 1]];
        s[b[i]]--;
    }
    cout << n * (n + 1) / 2 - ans << " " << ans << endl;
}