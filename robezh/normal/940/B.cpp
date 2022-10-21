#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,k,a,b;
ll sum = 0;

int main() {
    cin >> n >> k >> a >> b;
    if(k == 1){
        cout << (n-1) * a;
        return 0;
    }
    while(n > 1){
        if(n < k){
            sum += (n-1) * a;
            break;
        }
        sum += (n - n/k*k) * a;
        n = n/k*k;
        sum += min((n - n/k) * a, b);
        n = n/k;
    }
    cout << sum;
}