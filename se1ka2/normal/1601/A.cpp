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
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int g = 0;
        for(int j = 0; j < 30; j++){
            int c = 0;
            for(int i = 0; i < n; i++) c += (a[i] >> j) & 1;
            g = gcd(g, c);
        }
        for(int i = 1; i <= n; i++){
            if(g % i == 0) cout << i << " ";
        }
        cout << endl;
    }
}