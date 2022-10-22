#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll x;
        cin >> x;
        if(x < 14){
            cout << "NO" << endl;
            continue;
        }
        x %= 14;
        if(x != 0 && x <= 6) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}