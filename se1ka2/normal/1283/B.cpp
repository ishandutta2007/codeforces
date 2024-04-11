#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if((n % k) * 2 <= k) cout << n << endl;
        else cout << n - (n % k - k / 2) << endl;
    }
}