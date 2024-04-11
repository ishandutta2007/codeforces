#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll memo[100006];

ll fib(ll n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(memo[n]) return memo[n];
    return memo[n] = (fib(n - 1) + fib(n - 2)) % MOD;
}

int main()
{
    string s;
    cin >> s;
    ll n = s.size();
    s.push_back('.');
    ll l = 1;
    ll ans = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'n'){
            while(s[i + 1] == 'n'){
                i++;
                l++;
            }
            ans = (ans * fib(l)) % MOD;
            l = 1;
        }
        if(s[i] == 'u'){
            while(s[i + 1] == 'u'){
                i++;
                l++;
            }
            ans = (ans * fib(l)) % MOD;
            l = 1;
        }
        if(s[i] == 'w' || s[i] == 'm'){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}