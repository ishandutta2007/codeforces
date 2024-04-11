#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll c, sum;
        cin >> c >> sum;
        ll ans = 0;
        for(int j = 0; j < sum % c; j++){
            ans += (sum / c + 1) * (sum / c + 1);
        }
        for(int j = sum % c; j < c; j++){
            ans += (sum / c) * (sum / c);
        }
        cout << ans << endl;
    }
}