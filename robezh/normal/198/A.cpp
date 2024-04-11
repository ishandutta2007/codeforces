#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll k,b,n,t,x = 1;
    cin >> k >> b >> n >> t;
    while(x * k + b <= t){x = x*k+b; n--;}
    cout << (n > 0 ? n : 0);
}