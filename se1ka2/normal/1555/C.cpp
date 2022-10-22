#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        ll a[2][100005];
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < m; j++) cin >> a[i][j];
        }
        ll s[2]{0};
        for(int j = m - 1; j >= 1; j--) s[0] += a[0][j];
        ll ans = s[0] + s[1];
        for(int j = 0; j < m; j++){
            ans = min(ans, max(s[0], s[1]));
            s[0] -= a[0][j + 1];
            s[1] += a[1][j];
        }
        cout << ans << endl;
    }
}