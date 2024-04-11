#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 3005;

char a[3][3] , b[3][3];
int A[10] , B[10];

int main() {
    int n = 2;
    int m ;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s" , a[i]);
    }
    for (int i = 0 ; i < n ; ++ i)
        scanf("%s" , b[i]);

    for (int i = 0 ; i < 1000 ; ++ i) {

        if (a[0][0] == 'X') {
            swap(a[0][0], a[0][1]);
        } else if (a[0][1] == 'X') {
            swap(a[0][1], a[1][1]);
        } else if (a[1][1] == 'X') {
            swap(a[1][1], a[1][0]);
        } else {
            swap(a[1][0], a[0][0]);
        }
        if (memcmp(a , b , sizeof(a)) == 0) {
            puts("YES");
            return 0;
        }

    }
    puts("NO");
    return 0;
}