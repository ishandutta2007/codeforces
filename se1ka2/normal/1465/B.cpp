#include <iostream>
using namespace std;
typedef long long ll;

bool f(ll n){
    ll m = n;
    bool b[10]{0};
    while(m){
        b[m % 10] = true;
        m /= 10;
    }
    bool res = true;
    for(int i = 1; i < 10; i++){
        if(b[i] && n % i) res = false;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        for(ll i = 0; i < 3000; i++){
            if(f(n + i)){
                cout << n + i << endl;
                break;
            }
        }
    }
}