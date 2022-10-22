#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    ll a[100005];
    while(t--){
        int n;
        cin >> n;
        int l = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > a[l]) l = i;
        }
        ll s = 0;
        for(int i = 0; i < n; i++){
            if(l != i) s += a[i];
        }
        cout << fixed << setprecision(15) << (a[l] + s * 1.0 / (n - 1)) << endl;
    }
}