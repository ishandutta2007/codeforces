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
        ll h[102];
        for(int i = 0; i < n; i++) cin >> h[i];
        ll l = 0;
        bool f = true;
        for(int i = 0; i < n; i++){
            if(h[i] < i){
                if(h[i] + l < i){
                    f = false;
                    break;
                }
                l -= i - h[i];
            }
            else{
                l += h[i] - i;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}