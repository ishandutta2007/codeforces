#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    bool f = false;
    for(ll i = 2; i < 100002; i++){
        if(n % i == 0){
            n -= i;
            f = true;
            break;
        }
    }
    if(!f) cout << 1 << endl;
    else cout << n / 2 + 1 << endl;
}