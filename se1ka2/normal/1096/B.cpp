#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll l;
    for(l = 1; l < n; l++){
        if(s[l] != s[l - 1]) break;
    }
    ll r;
    for(r = 1; r < n; r++){
        if(s[n - r - 1] != s[n - r]) break;
    }
    if(l == n){
        cout << n * (n + 1) / 2 % MOD << endl;
    }
    else if(s[0] != s[n - 1]){
        cout << (l + 1) + (r + 1) - 1 << endl;
    }
    else{
        cout << (l + 1) * (r + 1) % MOD << endl;
    }
}