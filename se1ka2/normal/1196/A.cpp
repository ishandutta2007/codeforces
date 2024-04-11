#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        cout << (a + b + c) / 2 << endl;
    }
}