#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 10000000000000000;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll c[100005];
        for(int i = 0; i < n; i++) cin >> c[i];
        ll s[2] = {0, 0};
        ll l[2] = {INF, INF};
        ll ans = INF;
        for(int i = 0; i < n; i++){
            s[i % 2] += c[i];
            l[i % 2] = min(l[i % 2], c[i]);
            if(i >= 1){
                ans = min(ans, s[0] + l[0] * (n - i / 2 - 1) + s[1] + l[1] * (n - (i - 1) / 2 - 1));
            }
        }
        cout << ans << endl;
    }
}