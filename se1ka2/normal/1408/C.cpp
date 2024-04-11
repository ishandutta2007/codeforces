#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, l;
        cin >> n >> l;
        int a[100005];
        for(int i = 1; i <= n; i++) cin >> a[i];
        a[0] = 0;
        a[n + 1] = l;
        n += 2;
        double right = 1000000000, left = 0;
        for(int c = 0; c < 200; c++){
            double mid = (right + left) / 2;
            double d1 = 0, d2 = a[n - 1];
            double r1 = mid, r2 = mid;
            for(int i = 1; i < n; i++){
                if(r1 * i > a[i] - a[i - 1]){
                    d1 = a[i];
                    r1 -= (a[i] - a[i - 1]) * 1.0 / i;
                }
                else{
                    d1 += r1 * i;
                    break;
                }
            }
            for(int i = 1; i < n; i++){
                if(r2 * i > a[n - i] - a[n - i - 1]){
                    d2 = a[n - i - 1];
                    r2 -= (a[n - i] - a[n - i - 1]) * 1.0 / i;
                }
                else{
                    d2 -= r2 * i;
                    break;
                }
            }
            if(d1 > d2) right = mid;
            else left = mid;
        }
        cout << fixed << setprecision(15) << right << endl;
    }
}