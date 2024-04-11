#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll b[32]{0};
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            int j = 0;
            while(a){
                a >>= 1;
                j++;
            }
            b[j]++;
        }
        ll ans = 0;
        for(int i = 0; i < 32; i++) ans += b[i] * (b[i] - 1) / 2;
        cout << ans << endl;
    }
}