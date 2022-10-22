#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0)return a;
    else return gcd(b, a % b);
}

int get(int n, int m, int a){
    return (n / m) + (n % m >= a);
}

int main(){
    int n, m;
    cin >> n >> m;

    long long ans = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            if((i * i + j * j) % m == 0){
                ans += get(n, m, i) * 1ll * get(n, m, j);
            }
        }
    }

    cout << ans;
}