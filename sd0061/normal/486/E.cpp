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
typedef pair<int , int> Value;
void operator += (Value& A , const Value& B) {
    if (B.first > A.first)
        A = B;
    else if (A.first == B.first)
        (A.second += B.second) %= Q;
}
int n , a[N];
Value c[N] , L[N] , R[N];

int main() {
    int i , j , x;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    Value res = make_pair(0 , 0);
    for (i = 1 ; i <= n ; ++ i) {
        L[i] = make_pair(0 , 1);
        for (j = a[i] - 1 ; j > 0 ; j -= j & -j)
            L[i] += c[j];
        ++ L[i].first;
        for (j = a[i] ; j < N ; j += j & -j)
            c[j] += L[i];
        res += L[i];
    }
    memset(c , 0 , sizeof(c));
    for (i = n ; i > 0 ; -- i) {
        R[i] = make_pair(0 , 1);
        for (j = a[i] + 1 ; j < N ; j += j & -j)
            R[i] += c[j];
        ++ R[i].first;
        for (j = a[i] ; j > 0 ; j -= j & -j)
            c[j] += R[i];
    }
    for (i = 1 ; i <= n ; ++ i) {
        if (L[i].first + R[i].first - 1 == res.first) {
            if ((LL)L[i].second * R[i].second % Q == res.second)
                putchar('3');
            else
                putchar('2');
        } else
            putchar('1');
    }
    puts("");
    return 0;
}