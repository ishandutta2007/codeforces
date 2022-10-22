#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int d[1002][1002];

int main()
{
    int h, w;
    cin >> h >> w;
    int r[1002], c[1002];
    for(int i = 0; i < h; i++) cin >> r[i];
    for(int i = 0; i < w; i++) cin >> c[i];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < r[i]; j++) d[i][j] = 1;
        d[i][r[i]] = 2;
    }
    for(int j = 0; j < w; j++){
        for(int i = 0; i < c[j]; i++){
            if(d[i][j] == 0) d[i][j] = 1;
            if(d[i][j] == 2){
                cout << 0 << endl;
                return 0;
            }
        }
        if(d[c[j]][j] == 0) d[c[j]][j] = 2;
        if(d[c[j]][j] == 1){
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(d[i][j] == 0) ans = (ans * 2) % MOD;
    cout << ans << endl;
}