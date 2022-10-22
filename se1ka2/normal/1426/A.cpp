#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        if(n <= 2){
            cout << 1 << endl;
            continue;
        }
        cout << (n + x - 3) / x + 1 << endl;
    }
}