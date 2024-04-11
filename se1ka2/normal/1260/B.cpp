#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        if((a + b) % 3 == 0 && a <= b * 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}