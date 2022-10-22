#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        n += n % 2;
        n = max(n, 6ll);
        cout << n / 2 * 5 << endl;
    }
}