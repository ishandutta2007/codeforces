#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int f = 0; f < t; f++){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int p, pc;
        p = (a - 1) / c + 1;
        pc = (b - 1) / d + 1;
        if(p + pc <= k){
            cout << p << " " << pc << endl;
        }
        else cout << -1 << endl;
    }
}