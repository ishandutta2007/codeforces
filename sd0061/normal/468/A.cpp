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

int n;

void work() {
    cin >> n;
    if (n <= 3) {
        puts("NO");
        return;
    }
    puts("YES");
    if (n & 1) {
        printf("5 - 2 = 3\n");
        printf("3 - 1 = 2\n");
        for (int i = 6 ; i <= n ; i += 2) {
            printf("%d - %d = 1\n" , i + 1 , i);
            printf("2 * 1 = 2\n");
        }
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
    } else {

        for (int i = 5 ; i <= n ; i += 2) {
            printf("%d - %d = 1\n" , i + 1 , i);
            printf("1 * 1 = 1\n");
        }
        printf("1 * 2 = 2\n");
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
    }

}

int main() {
    //freopen("~input.txt" , "r" , stdin);

    work();
    return 0;
}