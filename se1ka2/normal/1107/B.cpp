#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    for(int c = 0; c < n; c++){
        ll k, x;
        cin >> k >> x;
        cout << (k - 1) * 9 + x << endl;
    }
}