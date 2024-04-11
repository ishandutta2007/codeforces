#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long LL;
const int N = 100005;
LL n , m ,  k , d1 , d2;

bool check(LL a , LL b , LL c) {
    LL w = k - b - c;
    if (w % 3) return 0;
    w /= 3;
    if (w < 0 || w + b < 0 || w + c < 0)
        return 0;
    if (w <= m && w + b <= m && w + c <= m)
        return 1;
    return 0;
}

void work() {
    cin >> n >> k >> d1 >> d2;
    if (n % 3 != 0) {
        puts("no");
        return;
    }
    m = n / 3;
    if (check(0 , d1 , d1 + d2)) puts("yes");
    else if (check(0 , d1 , d1 - d2)) puts("yes");
    else if (check(0 , -d1 , -d1 + d2)) puts("yes");
    else if (check(0 , -d1 , -d1 - d2)) puts("yes");
    else puts("no");
}

int main(){
    //freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}