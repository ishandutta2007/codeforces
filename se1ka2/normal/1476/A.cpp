#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k < n){
            if(n % k == 0) cout << 1 << endl;
            else cout << 2 << endl;
        }
        else cout << (k - 1) / n + 1 << endl;
    }
}