#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int l = max(a, max(b, c));
        n -= (l - a) + (l - b) + (l - c);
        if(n >= 0 && n % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}