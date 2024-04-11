#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105;

int n;
LL x;

void work() {
    LL res = 0;
    cin >> n >> x;
    -- x;
    int i , j;
    x |= 1LL << n;
    for (i = n - 1 ; i >= 0 ; -- i) {
        if ((x >> i & 1) == (x >> (i + 1) & 1)) {
            res += (1LL << i + 1);
        } else {
            ++ res;
        }
    }
    cout << res << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}