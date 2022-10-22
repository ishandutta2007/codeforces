#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;
        int a[3] = {min(k1, k2), abs(k1 - k2), n - max(k1, k2)};
        if(a[0] + a[1] / 2 >= w && a[2] + a[1] / 2 >= b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}