#include <iostream>
using namespace std;
typedef unsigned long long ll;

int main()
{
    int q;
    cin >> q;
    ll p[100];
    p[0] = 1;
    for(int i = 1; i < 41; i++) p[i] = p[i - 1] * 3;
    for(int c = 0; c < q; c++){
        ll n;
        cin >> n;
        int d[41];
        for(int i = 0; i < 41; i++){
            d[i] = n % 3;
            n /= 3;
        }
        int j = -1;
        for(int i = 40; i >= 0; i--){
            if(d[i] == 2){
                j = i;
                while(d[i] == 2){
                    d[i] = 0;
                    d[i + 1]++;
                    i++;
                }
                break;
            }
        }
        for(int i = 0; i < j; i++) d[i] = 0;
        ll ans = 0;
        ll b = 1;
        for(int i = 0; i < 41; i++){
            ans += b * d[i];
            b *= 3;
        }
        cout << ans << endl;
    }
}