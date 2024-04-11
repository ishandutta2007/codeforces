#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll l, r, m;
        cin >> l >> r >> m;
        ll d = (r - l);
        ll a, b = -1, c = -1;
        for(a = l; a <= r; a++){
            if(max((m - d - 1) / a, 0ll) < (m + d) / a){
                for(int i = -d; i <= d; i++){
                    if((m - i) % a == 0 && (m - i) / a > 0){
                        if(i >= 0){
                            b = r, c = r - i;
                        }
                        else{
                            b = r + i, c = r;
                        }
                        break;
                    }
                }
                break;
            }
        }
        cout << a << " " << b << " " << c << endl;
    }
}