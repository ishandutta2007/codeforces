#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2005;

int dig(LL x) {
    if (x < 0) return -1;
    int res = 0;
    while (x)
        res += x % 10 , x /= 10;
    return res;
}

void work() {
    int a , b , c;
    cin >> a >> b >> c;
    vector<int> res;
    for (int i = 1 ; i <= 81 ; ++ i) {
        LL x = 1;
        for (int j = 0 ; j < a ; ++ j)
            x *= i;
        x = b * x + c;
        if (dig(x) == i && x < 1000000000)
            res.push_back(x);
    }
    sort(res.begin() , res.end());
    printf("%d\n" , res.size());
    for (int i = 0 ; i < res.size() ; ++ i)
        printf("%d " , res[i]);
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}