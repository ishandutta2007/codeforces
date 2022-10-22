#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll n, x;
        cin >> n >> x;
        ll d[102], h[102];
        ll lard = 0;
        ll lar = 0;
        for(int i = 0; i < n; i++){
            cin >> d[i] >> h[i];
            lard = max(lard, d[i]);
            lar = max(lar, d[i] - h[i]);
        }
        x -= lard;
        if(x <= 0){
            cout << 1 << endl;
            continue;
        }
        if(lar == 0){
            cout << -1 << endl;
            continue;
        }
        cout << (x + lar - 1) / lar + 1 << endl;
    }
}