#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        ll l, r, d;
        cin >> l >> r >> d;
        if(d < l) cout << d << endl;
        else cout << (r / d + 1) * d << endl;
    }
}