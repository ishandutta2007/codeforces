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
        while(n % 2 == 0) n /= 2;
        if(n == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}