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
const int N = 100005;
const int Q = 1e9 + 7;
void add(int& A , int B) {
    A += B;
    if (A >= Q)
        A -= Q;
}

int n , m ;
char s[N] , t[N];
int f[N] , c[N] , p[N];

void work() {
    int i , j , k , l;
    scanf("%s%s" , s , t);
    n = strlen(s) , m = strlen(t);
    f[0] = f[1] = 0;
    for (i = 1 ; i < m ; ++ i) {
        j = f[i];
        while (j && t[i] != t[j])
            j = f[j];
        f[i + 1] = (t[i] == t[j]) ? j + 1 : 0;
    }
    j = 0 , k = -1;
    p[0] = 1;
    for (i = 0 ; i <= n ; i += ~i & i + 1)
        add(c[i] , 1);
    for (i = 0 ; i < n ; ++ i) {
        while (j && s[i] != t[j])
            j = f[j];
        j += (s[i] == t[j]);
        if (j == m) {
            k = i - m + 1;
        //    cout << i << endl;
        }
        p[i + 1] = p[i];
        for (l = k ; l >= 0 ; l -= ~l & l + 1)
            add(p[i + 1] , c[l]);
        for (l = i + 1 ; l <= n ; l += ~l & l + 1)
            add(c[l] , p[i + 1]);
        //printf("%d %d : %d\n" , i + 1 , p[i + 1] , k);
    }
    add(p[n] , Q - 1);
    printf("%d\n" , p[n]);
}

int main() {
    work();
    return 0;
}