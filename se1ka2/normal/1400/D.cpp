#include <iostream>
using namespace std;
typedef long long ll;

ll s[3005][3005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[3005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
        }
        for(int c = 0; c < n; c++){
            s[c][0] = 0;
            for(int i = 1; i <= n; i++){
                s[c][i] = s[c][i - 1];
                if(a[i - 1] == c) s[c][i]++;
            }
        }
        ll ans = 0;
        for(int c = 0; c < n; c++){
            ll t = s[c][n];
            ans += t * (t - 1) * (t - 2) * (t - 3) / 24;
        }
        for(int c = 0; c < n; c++){
            ll d[3005]{0};
            int k = 0;
            for(int i = 0; i < n; i++){
                if(a[i] == c){
                    for(int j = 0; j < n; j++){
                        ans += d[j] * (s[j][n] - s[j][i]);
                    }
                    k++;
                }
                else d[a[i]] += k;
            }
        }
        cout << ans << endl;
    }
}