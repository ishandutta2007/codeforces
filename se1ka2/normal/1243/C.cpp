#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            if(n != 1) cout << 1 << endl;
            else cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
}