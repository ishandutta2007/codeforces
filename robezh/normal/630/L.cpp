#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k = 5;
    cin >> n;
    int a[5];
    for(int i = 0; i < 5; i++) a[i] = n % 10, n /= 10;
    n = a[4] * 10000 + a[2] * 1000 + a[0] * 100 + a[1] * 10 + a[3];
    long long res = 1;
    while(k--){res = (res * n) % 100000;}
    for(int i = 0; i < 5; i++) a[i] = res % 10, res /= 10;
    for(int i = 4; i >= 0; i--) cout << a[i];
}