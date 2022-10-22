#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int N = 200005;
typedef long long LL;

void work() {
    int a , b , c , d , e , f;
    cin >> a >> b >> c >> d >> e >> f;
    int res = 0 , x = 0;
    for (int i = 0 ; i < b ; ++ i)
        res += x + x + a + a + 1 + i + i;
    for (int i = 0 ; i < c ; ++ i)
        res += (x + x + a + b) * 2;
    for (int i = 0 ; i < e ; ++ i)
        res -= x + x + i + i + 1;
    for (int i = 0 ; i < f ; ++ i)
        res -= (x + x) * 2;            
    cout << res << endl;
}

int main() {
    work();
    return 0;
}