#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[100005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
        }
        while(n > 0 && a[n - 1] == n - 1) n--;
        double ans = 0;
        for(int i = 0; i < m; i++){
            int r;
            double p;
            cin >> r >> p;
            if(r >= n) ans = ans + (1 - ans) * p;
        }
        if(n == 0) ans = 1;
        cout << fixed << setprecision(15) << ans << endl;
    }
}