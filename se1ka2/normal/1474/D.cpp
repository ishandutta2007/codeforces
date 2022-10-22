#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        ll s[200005];
        s[0] = a[0];
        for(int i = 1; i < n; i++) s[i] = a[i] - s[i - 1];
        ll t[200005];
        t[n] = t[n + 1] = INF;
        for(int i = n - 1; i >= 0; i--) t[i] = min(s[i], t[i + 2]);
        bool f = false;
        if(s[n - 1] == 0 && t[0] >= 0 && t[1] >= 0) f = true;
        for(int i = 0; i < n - 1; i++){
            if(i % 2 != n % 2){
                if((a[i] - a[i + 1]) * 2 == s[n - 1] &&
                   s[i] + a[i + 1] - a[i] >= 0 &&
                   t[i + 1] >= (a[i + 1] - a[i]) * 2 &&
                   t[i + 2] >= (a[i] - a[i + 1]) * 2) f = true;
            }
            else{
                if((a[i + 1] - a[i]) * 2 == s[n - 1] &&
                   s[i] + a[i + 1] - a[i] >= 0 &&
                   t[i + 1] >= (a[i + 1] - a[i]) * 2 &&
                   t[i + 2] >= (a[i] - a[i + 1]) * 2) f = true;
            }
            if(s[i] < 0) break;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}