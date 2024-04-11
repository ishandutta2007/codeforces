#include <iostream>
using namespace std;
typedef long long ll;

int foo(ll n){
    int res = 0;
    while(n){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    ll p[20];
    p[0] = 1;
    for(int i = 1; i < 19; i++) p[i] = p[i - 1] * 10;
    while(t--){
        ll n;
        int s;
        cin >> n >> s;
        ll m = n;
        for(int i = 0; i < 18; i++){
            if(foo(n) <= s) break;
            if(n % p[i + 1]) n = (n / p[i + 1] + 1) * p[i + 1];
        }
        cout << n - m << endl;
    }
}