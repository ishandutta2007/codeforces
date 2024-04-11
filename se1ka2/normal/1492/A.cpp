#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        cout << min({(a - p % a) % a, (b - p % b) % b, (c - p % c) % c}) << endl;
    }
}