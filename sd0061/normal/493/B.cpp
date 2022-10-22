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
int n , a[N];
vector< int > A , B;

void work() {
    int i , x;
    LL sa = 0 , sb = 0;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d" , &x);
        if (x > 0)
            sa += x , A.push_back(x);
        else
            sb -= x , B.push_back(-x);
    }
    if (sa == sb) {
        if (A != B)
            puts(A > B ? "first" : "second");
        else
            puts(x > 0 ? "first" : "second");
    } else {
        puts(sa > sb ? "first" : "second");
    }

}

int main() {
    work();
    return 0;
}