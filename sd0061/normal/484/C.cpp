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
const int N = 1000005;

typedef vector<int> Permutation;
Permutation operator * (const Permutation& A , const Permutation& B) {
    Permutation C(A.size());
    for (int i = 0 ; i < A.size() ; ++ i)
        C[i] = A[B[i]];
    return C;
}
int n , m ;
char str[N];

int main() {
    int i , x , y , k , d;
    scanf("%s" , str);
    n = strlen(str);
    scanf("%d",&m);

    Permutation P(n) , A(n) , B(n);
    for (i = 0 ; i < n ; ++ i)
        P[i] = i;
    while (m --) {
        scanf("%d%d",&k,&d);
        for (i = k ; i < n ; ++ i)
            A[i] = i;
        y = 0;
        for (x = 0 ; x < d ; ++ x)
            for (i = x ; i < k ; i += d)
                A[y ++] = i;
        rotate(A.begin() , A.begin() + 1 , A.end());
//        for (i = 0 ; i < n ; ++ i)
//            printf("%d%c" , A[i] , " \n"[i + 1 == n]);
        y = n - k + 1;
        while (y) {
            if (y & 1)
                P = P * A;
            A = A * A , y >>= 1;
        }
        rotate(P.begin() , P.begin() + k - 1 , P.end());
//        for (i = 0 ; i < n ; ++ i)
//            printf("%d%c" , P[i] , " \n"[i + 1 == n]);
        for (i = 0 ; i < n ; ++ i)
            putchar(str[P[i]]);
        puts("");
    }

    return 0;
}