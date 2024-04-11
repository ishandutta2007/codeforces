#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> b[i];

    for(int i = 0; i < n; i++)if(a[i] <= 1 || b[i] <= 1){
        cout << -1;
        return 0;
    }

    long double k = m + (long double)m / (b[0] - 1);
    for(int i = n - 1; i >= 0; i--){
        k += k / (a[i] - 1);
        if(i > 0)k += k / (b[i] - 1);
    }

    cout << setprecision(6) << fixed;
    cout << k - m;

}