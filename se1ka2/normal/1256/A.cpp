#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int a, b, n, s;
        cin >> a >> b >> n >> s;
        s -= min(a, s / n) * n;
        if(s <= b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}