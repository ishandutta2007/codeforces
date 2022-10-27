#include <iostream>
using namespace std;
typedef long long LL;
LL l, r, x, y, k;
int main()
{
    cin >> l >> r >> x >> y >> k;
    int ok = 0;
    for(LL b = x; b <= y; b ++)
    {
        if(b*k <= r && b*k >= l) ok = 1;
    }
    printf("%s\n", ok?"YES":"NO");

}