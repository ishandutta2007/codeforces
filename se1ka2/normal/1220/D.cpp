#include <iostream>
using namespace std;
typedef long long ll;

ll power(ll x, ll n){
    ll res = 1;
    for(int i = 0; i < n; i++) res *= x;
    return res;
}

int main()
{
    int n;
    cin >> n;
    ll b[200003];
    ll bb[200003];
    int arg = 0;
    int ans = n;
    for(int i = 0; i < n; i++){
        scanf("%lld", &b[i]);
        bb[i] = b[i];
        if(b[i] % 2) ans--;
    }
    for(int j = 0; j < 70; j++){
        int now = 0;
        for(int i = 0; i < n; i++){
            if(bb[i] % 2 == 0){
                bb[i] /= 2;
                if(bb[i] % 2 == 1) now++;
            }
        }
        if(n - now < ans){
            ans = n - now;
            arg = j + 1;
        }
    }
    cout << ans << endl;
    ll t = power(2, arg);
    for(int i = 0; i < n; i++){
        if(!(b[i] % t == 0 && b[i] % (t * 2) != 0)) cout << b[i] << " ";
    }
    cout << endl;
}