#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll s[5002];
        for(int i = 0; i < n; i++) cin >> s[i];
        ll ans = 0;
        int right[5002];
        for(int i = 0; i < n; i++){
            if(s[i] == 1) right[i] = i + 1;
            else right[i] = i;
        }
        for(int i = 0; i < n; i++){
            ans += s[i] - 1;
            ll h = min(s[i], n);
            s[i] = h;
            for(int j = 0; j < h - 1; j++){
                int k = i;
                while(k < n){
                    if(s[k] == 1){
                        right[k] = max(k + 1, right[right[k]]);
                        k = right[k];
                    }
                    else{
                        s[k]--;
                        k += s[k] + 1;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}