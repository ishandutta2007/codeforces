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
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 200005;

void work() {
    int n ;
    scanf("%d",&n);
    if (n & 1) {
        puts("black");
    } else {
        puts("white\n1 2");
    }
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}