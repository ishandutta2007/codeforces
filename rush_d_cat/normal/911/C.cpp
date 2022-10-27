#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL a[4];
int main() {
    for (int i = 1; i <= 3; i ++) cin >> a[i];
    sort(a+1,a+1+3);
    if (a[1] == 1) {
        printf("YES\n"); return 0;
    } 
    if (a[1] == 2 && a[2] == 2) {
        printf("YES\n"); return 0;
    }
    if (a[1] == 2 && a[2] == 4 && a[3] == 4) {
        printf("YES\n"); return 0;
    }
    if (a[1] == 3 && a[2] == 3 && a[3] == 3) {
        printf("YES\n"); return 0;
    }
    printf("NO\n");
}