#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll c[502][502];
        for(int i = 0; i < n * 2; i++){
            for(int j = 0; j < n * 2; j++) cin >> c[i][j];
        }
        ll ans = 0;
        for(int i = n; i < n * 2; i++){
            for(int j = n; j < n * 2; j++) ans += c[i][j];
        }
        ans += min({c[0][n], c[0][n * 2 - 1], c[n - 1][n], c[n - 1][n * 2 - 1], c[n][0], c[n][n - 1], c[n * 2 - 1][0], c[n * 2 - 1][n - 1]});
        cout << ans << "\n";
    }
}