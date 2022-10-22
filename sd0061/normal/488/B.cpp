#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , a[N];

bool check(int a , int b , int c , int d) {
    int w[4] = {a , b , c , d};
    sort(w , w + 4);
    int X = w[0] + w[1] + w[2] + w[3];
    int Y = w[1] + w[1] + w[2] + w[2];
    int Z = 4 * (w[3] - w[0]);
    if (X != Y || X != Z || Y != Z)
        return 0;
    else
        return 1;
}

void work() {
    cin >> n;
    for (int i = 0 ; i < n ; ++ i)
        cin >> a[i];
    sort(a , a + n);
    if (n == 0) {
        puts("YES\n1\n1\n3\n3");
    } else if (n == 1) {
        printf("YES\n%d\n%d\n%d\n" , a[0] , a[0] * 3 , a[0] * 3);
    } else if (n == 4) {
        if (!check(a[0] , a[1] , a[2] , a[3]))
            puts("NO");
        else
            puts("YES");
    } else if (n == 2) {
        for (int i = 1 ; i <= 2000 ; ++ i)
            for (int j = 1 ; j <= 2000 ; ++ j)
                if (check(a[0] , a[1] , i , j)) {
                    printf("YES\n%d\n%d\n" , i , j);
                    return;
                }
        puts("NO");
    } else {
        for (int i = 1 ; i <= 2000 ; ++ i) {
            if (check(a[0] , a[1] , a[2] , i)) {
                printf("YES\n%d\n" , i);
                return;
            }
        }
        puts("NO");
    }
}

int main() {
    work();
    return 0;
}