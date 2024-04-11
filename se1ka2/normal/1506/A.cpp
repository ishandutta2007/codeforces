#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, m, x;
        cin >> n >> m >> x;
        x--;
        ll i = x / n, j = x % n;
        cout << j * m + i + 1 << endl;
    }
}