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
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 131072;

void work() {
    int n = 0;
    for (int i = 0 , x ; i < 5 ; ++ i) {
        scanf("%d",&x);
        n += x;
    }
    if ((n % 5) || !n)
        puts("-1");
    else
        printf("%d\n" , n / 5);
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}