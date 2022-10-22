#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        double x[100005], y[100005];
        int a = 0, b = 0;
        for(int i = 0; i < n * 2; i++){
            int u, v;
            cin >> u >> v;
            if(v == 0) x[a++] = u;
            else y[b++] = v;
        }
        for(int i = 0; i < n; i++) x[i] = abs(x[i]);
        for(int i = 0; i < n; i++) y[i] = abs(y[i]);
        sort(x, x + n);
        sort(y, y + n);
        double ans = 0;
        for(int i = 0; i < n; i++) ans = ans + sqrt(x[i] * x[i] + y[i] * y[i]);
        cout << fixed << setprecision(15) << ans << endl;
    }
}