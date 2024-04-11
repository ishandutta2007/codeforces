#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;
int A , B , n;
void work() {
    cin >> A >> B;
    n = A + B + 1;
    if (n == 1) {
        puts("1");
        return;
    }
    if (A + 1 == n) {
        for (int i = 1 ; i <= n ; ++ i)
            printf("%d%c" , i , " \n"[i == n]);
        return;
    }
    if (B + 1 == n) {
        for (int i = n ; i > 0 ; -- i)
            printf("%d%c" , i , " \n"[i == 1]);
        return;
    }
    printf("1 ");
    for (int i = n - A + 1 ; i <= n ; ++ i)
        printf("%d " , i);
    for (int i = n - A ; i > 1 ; -- i)
        printf("%d " , i);
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}