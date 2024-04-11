#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int t = 0; t < q; t++){
        int c, m, x;
        cin >> c >> m >> x;
        cout << min(min(c, m), (c + m + x) / 3) << endl;
    }
}