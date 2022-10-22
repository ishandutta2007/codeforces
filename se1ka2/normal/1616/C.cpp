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
        int a[73];
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = n - 1;
        for(int l = 0; l < n; l++){
            for(int r = l + 1; r < n; r++){
                int g = gcd(r - l, abs(a[r] - a[l]));
                int d = (r - l) / g, h = (a[r] - a[l]) / g;
                int c = 0;
                for(int i = 0; i < n; i++){
                    if(abs(l - i) % d) c++;
                    else if(a[l] - (l - i) / d * h != a[i]) c++;
                }
                ans = min(ans, c);
            }
        }
        cout << ans << endl;
    }
}