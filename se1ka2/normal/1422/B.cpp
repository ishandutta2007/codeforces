#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        ll a[102][102];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cin >> a[i][j];
        }
        ll ans = 0;
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < m / 2; j++){
                ll d[4];
                d[0] = a[i][j];
                d[1] = a[i][m - 1 - j];
                d[2] = a[n - 1 - i][j];
                d[3] = a[n - 1 - i][m - 1 - j];
                sort(d, d + 4);
                ans += d[3] - d[0] + d[2] - d[1];
            }
            if(m % 2){
                ll d[2];
                d[0] = a[i][m / 2];
                d[1] = a[n - 1 - i][m / 2];
                ans += abs(d[1] - d[0]);
            }
        }
        if(n % 2){
            for(int j = 0; j < m / 2; j++){
                ll d[2];
                d[0] = a[n / 2][j];
                d[1] = a[n / 2][m - 1 - j];
                ans += abs(d[1] - d[0]);
            }
        }
        cout << ans << endl;
    }
}