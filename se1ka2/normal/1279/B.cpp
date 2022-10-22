#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++){
        ll n, s;
        cin >> n >> s;
        ll a[100002];
        for(int i = 0; i < n; i++) cin >> a[i];
        ll l = 0;
        int al = -1;
        ll r = 0;
        for(int i = 0; i < n; i++){
            if(r > s){
                if(a[i] > s - (r - l)) break;
            }
            r += a[i];
            if(a[i] > l){
                l = a[i];
                al = i;
            }
        }
        if(r <= s) cout << 0 << endl;
        else cout << al + 1 << endl;
    }
}