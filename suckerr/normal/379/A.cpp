#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int a, b;
int ans;

int main() {
    scanf("%d %d", &a, &b);
    ans = a;
    while(a >= b) {
        ans += a / b;
        a = a % b + a / b;
    }   
    printf("%d", ans);
    return 0;
}