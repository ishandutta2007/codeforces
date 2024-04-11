#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[200005];
    int p[20]{0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < 20; j++){
            if((a[i] >> j) & 1){
                a[i] -= (1 << j);
                a[p[j]] += (1 << j);
                p[j]++;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += a[i] * a[i];
    cout << ans << endl;
}