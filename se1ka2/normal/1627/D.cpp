#include <iostream>
#include <vector>
using namespace std;

int gcd(int n, int m){
    if(m == 0) return n;
    return gcd(m, n % m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[1000005];
    bool b[1000005]{0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[a[i]] = true;
    }
    int ans = -n;
    for(int i = 1; i <= 1000000; i++){
        int g = 0;
        for(int j = i; j <= 1000000; j += i){
            if(b[j]) g = gcd(g, j);
        }
        if(g == i) ans++;
    }
    cout << ans << "\n";
}