#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int v, a, l, c, mx_v, res = 0;
    cin >> c >> v >> mx_v >> a >> l;
    do{
        c -= v;
        v = min(mx_v, v + a);
        ++res;
        if(c > 0)
            c += l;
    } while(c > 0);
    cout << res;
    return 0;
}