#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 2000005;

LL n , va , vb , wa , wb;
void work() {
    LL res = 0;
    cin >> n >> va >> vb >> wa >> wb;
    for (LL i = 0 ; i <= 1000000 && wa * i <= n ; ++ i)
        res = max(res , i * va + (n - wa * i) / wb * vb);
    swap(va , vb) , swap(wa , wb);
    for (LL i = 0 ; i <= 1000000 && wa * i <= n ; ++ i)
        res = max(res , i * va + (n - wa * i) / wb * vb);
    cout << res << endl;    
}

int main() {
    work();
    return 0;
}