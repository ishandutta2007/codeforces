#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[52];
        ll s[2]{0};
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s[i % 2] += a[i];
        }
        for(int i = 0; i < n; i++){
            if(s[i % 2] > s[(i + 1) % 2] || (s[i % 2] == s[(i + 1) % 2] && i % 2 == 0)) cout << a[i] << " ";
            else cout << 1 << " ";
        }
        cout << endl;
    }
}