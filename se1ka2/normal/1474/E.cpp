#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll s = 0;
        bool f = true;
        ll m = n - 1;
        for(int i = 0; i < n - 1; i++){
            s += m * m;
            if(f) m--;
            f = !f;
        }
        cout << s << "\n";
        cout << (n + 2) / 2 << " ";
        for(int i = 1; i < n / 2; i++) cout << i << " ";
        for(int i = (n + 4) / 2; i <= n; i++) cout << i << " ";
        cout << n / 2 << "\n";
        cout << n - 1 << "\n";
        for(int i = (n + 2) / 2; i < n; i++) cout << i << " " << 1 << "\n";
        for(int i = n / 2; i >= 1; i--) cout << i << " " << n << "\n";
    }
}