#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,k;

int main(){
    cin >> n >> m >> k;
    if(k < n){cout << (k+1) << " " << 1;}
    else{
        ll x = n - (k-n) / (m-1);
        ll y = (x % 2 == 0 ? (k - n) % (m-1) + 2 : m - (k-n)%(m-1));

        cout << x << " " << y << endl;
    }
}