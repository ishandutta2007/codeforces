#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n < 31){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            int k = n - 6 - 10 - 14;
            if(k == 6 || k == 10 || k == 14) cout << "6 10 15 " << k - 1 << endl;
            else cout << "6 10 14 " << k << endl;
        }
    }
}