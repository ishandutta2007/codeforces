#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

LL x , y;
void work() {
    cin >> x >> y;
    if (y > x)
        puts("0");
    else if (y == x)
        printf("infinity");
    else {
        x -= y;
        int res = 0;
        for (int i = 1 ; i * i <= x ; ++ i) {
            if (x % i == 0) {
                res += (i > y);
                if (i * i != x)
                    res += ((x / i) > y);
            }
        }
        cout << res << endl;
    }
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}