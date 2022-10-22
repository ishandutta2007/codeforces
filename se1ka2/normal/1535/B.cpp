#include <iostream>
using namespace std;

int gcd(int n, int m){
    if(m == 0) return n;
    return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[2002];
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(gcd(a[i], a[j]) > 1) ans++;
                else if(a[i] % 2 == 0 || a[j] % 2 == 0) ans++;
            }
        }
        cout << ans << endl;
    }
}