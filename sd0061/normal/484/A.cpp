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
const int N = 100005;
const int Q = 1e9 + 7;

int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        LL L , R , res;
        scanf("%I64d%I64d",&L,&R);
        while (L <= R) {
            res = L;
            L += (~L & -~L);
        }
        printf("%I64d\n" , res);
    }
    return 0;
}