#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int N = 200005;

int n , d , h;
int main() {
    cin >> n >> d >> h;

    if (h > d) {
        puts("-1");
        return 0;
    }

    if (d == h) {
        if (h < 2 && n > 2) {
            puts("-1");
            return 0;
        }
        for (int i = 1 ; i <= h ; ++ i) {
            printf("%d %d\n" , i , i + 1);
        }
        int x = 2;
        for (int i = d + 2 ; i <= n ; ++ i) {
            printf("%d %d\n" , x , i);
        }
    } else {
        if (d - h > h) {
            puts("-1");
            return 0;
        }
        for (int i = 1 ; i <= h ; ++ i) {
            printf("%d %d\n" , i , i + 1);
        }
        int x = 1;
        for (int i = h + 2 ; i <= d + 1 ; ++ i) {
            printf("%d %d\n" , x , i);
            x = i;
        }
        for (int i = d + 2 ; i <= n ; ++ i) {
            printf("%d %d\n" , 1 , i);
        }
    }

    return 0;
}