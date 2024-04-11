#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b) swap(a, b);
        int n = (b - a) * 2;
        if(b > n || c > n){
            cout << -1 << endl;
            continue;
        }
        int d = (c + n / 2 - 1) % n + 1;
        cout << d << endl;
    }
}