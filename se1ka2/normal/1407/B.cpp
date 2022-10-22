#include <iostream>
using namespace std;

int gcd(int n, int m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int b[1005];
        for(int i = 0; i < n; i++) cin >> b[i];
        int k = 0;
        bool f[1005];
        for(int i = 0; i < n; i++) f[i] = true;
        for(int c = 0; c < n; c++){
            int l = -1;
            for(int i = 0; i < n; i++){
                if(!f[i]) continue;
                if(l == -1 || gcd(k, b[i]) >= gcd(k, b[l])) l = i;
            }
            k = gcd(k, b[l]);
            f[l] = false;
            cout << b[l] << " ";
        }
        cout << endl;
    }
}