#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        ll x, y;
        cin >> x >> y;
        if(x - y == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}